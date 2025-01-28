#pragma once

#include "Color.h"
#include "Linalg.h"
#include "Vertex.h"

#include "Eigen/Geometry"

#include <functional>

namespace r3d {

class ConstMeshIterator;

class Object {
	friend class ProxyMesh;
	friend class ConstMeshIterator;

	using Transform = Eigen::Affine3f;
	using Rotation = Eigen::AngleAxisf;

public:
	Object(const Vec3f& position = Vec3f::Zero());

	void addVertex(const Vertex& vertex);
	void addMesh(Index v1, Index v2, Index v3);

	void move(const Vec3f& movement);
	void scale(const Vec3f& scale);
	void rotate(Angle angle, const Vec3f& axis);

	ConstMeshIterator begin() const;
	ConstMeshIterator end() const;

private:
	struct InnerMesh {
		Index vertices[3];
	};

	Transform transform_;

	std::vector<Vec4f> positions_;
	std::vector<Color3f> colors_;
	// std::vector<Vec3f> normals;

	std::vector<InnerMesh> meshes_;
};

class ProxyMesh {
	friend class ConstMeshIterator;

	using MeshCRef = std::reference_wrapper<const Object::InnerMesh>;
	using ObjectCRef = std::reference_wrapper<const Object>;

public:
	Vec4f position(Index index) const;
	Color3f color(Index index) const;

private:
	MeshCRef mesh_;
	ObjectCRef object_;

	ProxyMesh(MeshCRef mesh, ObjectCRef object);
};

class ConstMeshIterator {
	friend class Object;

	using RawIterator = std::vector<Object::InnerMesh>::const_iterator;
	using ObjectCRef = std::reference_wrapper<const Object>;

public:
	ProxyMesh operator*();

	ConstMeshIterator& operator++();
	ConstMeshIterator& operator--();

	bool operator==(const ConstMeshIterator& other) const;
	bool operator!=(const ConstMeshIterator& other) const;

private:
	ConstMeshIterator(RawIterator iter, ObjectCRef object);

	RawIterator iter_;
	ObjectCRef object_;
};

/*

using:

for (const Object& obj : objects) {
	for (ProxyMesh mesh : obj) {
		render mesh
	}
}

*/

} // namespace r3d
