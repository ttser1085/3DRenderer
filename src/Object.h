#pragma once

#include "Color.h"
#include "Vertex.h"

#include <functional>

namespace r3d {

class ConstMeshIterator;

class Object {
	friend class ProxyMesh;
	friend class ConstMeshIterator;

	using Index = inttypes::Index;

	using Transform = linalg::AffineTransform;
	using Rotation = linalg::Rotation;

public:
	explicit Object(const Vec3& position = Vec3::Zero());

	void addVertex(const Vertex& vertex);
	void addMesh(Index v1, Index v2, Index v3);

	void move(const Vec3& movement);
	void scale(const Vec3& scale);
	void rotate(linalg::Angle angle, const Vec3& axis);

	ConstMeshIterator begin() const;
	ConstMeshIterator end() const;

private:
	struct InnerMesh {
		Index vertices[3];
	};

	Transform transform_;

	std::vector<Vec4> positions_;
	std::vector<Color3f> colors_;
	// std::vector<Vec3> normals;

	std::vector<InnerMesh> meshes_;
};

class ProxyMesh {
	friend class ConstMeshIterator;

	using Index = inttypes::Index;
	using MeshCRef = std::reference_wrapper<const Object::InnerMesh>;
	using ObjectCRef = std::reference_wrapper<const Object>;

public:
	Vec4 position(Index index) const;
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
