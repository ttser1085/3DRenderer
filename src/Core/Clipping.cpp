#include "Clipping.h"

#include "Linalg/Interpolation.h"

namespace r3d {

std::vector<Mesh> clip(ProxyMesh mesh, const lalg::Plane& plane) {
	return clip(Mesh{Vertex{mesh.position(0), mesh.color(0)},
					 Vertex{mesh.position(1), mesh.color(1)},
					 Vertex{mesh.position(2), mesh.color(2)}},
				plane);
}

std::vector<Mesh> clip(const Mesh& mesh, const lalg::Plane& plane) {
	using lalg::Line, lalg::homoNormalized;

	std::vector<Index> inner;
	std::vector<Index> outer;

	for (Index i = 0; i < 3; ++i) {
		if (plane.signedDistance(homoNormalized(mesh[i].pos).head<3>()) <
			0.0f) {
			inner.push_back(i);
		} else {
			outer.push_back(i);
		}
	}

	assert(inner.size() + outer.size() == 3);

	if (inner.size() == 3) {
		return {mesh};
	}

	if (outer.size() == 3) {
		return {};
	}

	if (outer.size() == 1) {
		Vec4 outer1 = homoNormalized(mesh[outer[0]].pos);
		Vec4 inner1 = homoNormalized(mesh[inner[0]].pos);
		Vec4 inner2 = homoNormalized(mesh[inner[1]].pos);

		Line line1 = Line::Through(inner1.head<3>(), outer1.head<3>());
		Line line2 = Line::Through(inner2.head<3>(), outer1.head<3>());

		Vec4 p1 = homoNormalized(line1.intersectionPoint(plane));
		Vec4 p2 = homoNormalized(line2.intersectionPoint(plane));

		Color3f c1 = lalg::linearCombination<Color3f>(
			lalg::barycentric(p1.head<3>(), inner1.head<3>(), outer1.head<3>()),
			mesh[inner[0]].color, mesh[outer[0]].color);

		Color3f c2 = lalg::linearCombination<Color3f>(
			lalg::barycentric(p1.head<3>(), inner2.head<3>(), outer1.head<3>()),
			mesh[inner[1]].color, mesh[outer[0]].color);

		return {Mesh{
					Vertex{inner1, mesh[inner[0]].color},
					Vertex{p1, c1},
					Vertex{p2, c2},
				},
				Mesh{
					Vertex{inner1, mesh[inner[0]].color},
					Vertex{p2, c2},
					Vertex{inner2, mesh[inner[1]].color},
				}};
	}

	if (outer.size() == 2) {
		Vec4 inner1 = homoNormalized(mesh[inner[0]].pos);
		Vec4 outer1 = homoNormalized(mesh[outer[0]].pos);
		Vec4 outer2 = homoNormalized(mesh[outer[1]].pos);

		Line line1 = Line::Through(inner1.head<3>(), outer1.head<3>());
		Line line2 = Line::Through(inner1.head<3>(), outer2.head<3>());

		Vec4 p1 = homoNormalized(line1.intersectionPoint(plane));
		Vec4 p2 = homoNormalized(line2.intersectionPoint(plane));

		Color3f c1 = lalg::linearCombination<Color3f>(
			lalg::barycentric(p1.head<3>(), inner1.head<3>(), outer1.head<3>()),
			mesh[inner[0]].color, mesh[outer[0]].color);

		Color3f c2 = lalg::linearCombination<Color3f>(
			lalg::barycentric(p1.head<3>(), inner1.head<3>(), outer2.head<3>()),
			mesh[inner[0]].color, mesh[outer[1]].color);

		return {Mesh{
			Vertex{inner1, mesh[inner[0]].color},
			Vertex{p1, c1},
			Vertex{p2, c2},
		}};
	}

	assert(false);
}

std::vector<Mesh> clip(ProxyMesh mesh, const std::vector<lalg::Plane>& planes) {
	if (planes.empty()) {
		return {Mesh{Vertex{mesh.position(0), mesh.color(0)},
					 Vertex{mesh.position(1), mesh.color(1)},
					 Vertex{mesh.position(2), mesh.color(2)}}};
	}

	static constexpr Index kMaxMeshesNum = 10; // ???

	std::vector<Mesh> meshes1 = clip(mesh, planes.front()), meshes2;
	meshes1.reserve(kMaxMeshesNum);
	meshes2.reserve(kMaxMeshesNum);

	for (const auto& plane : planes) {
		for (const auto& m : meshes1) {
			auto new_meshes = clip(m, plane);
			meshes2.insert(meshes2.end(), new_meshes.begin(), new_meshes.end());
		}

		std::swap(meshes1, meshes2);
		meshes2.clear();
	}

	return meshes1;
}

} // namespace r3d
