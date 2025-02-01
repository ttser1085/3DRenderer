#include "Object.h"

namespace r3d {

// Object

Object::Object(const Vec3& position) {
	transform_.setIdentity();
	transform_.translate(position);
}

void Object::addVertex(const Vertex& vertex) {
	positions_.push_back(vertex.pos);
	colors_.push_back(vertex.color);
}

void Object::addMesh(Index v1, Index v2, Index v3) {
	meshes_.push_back(InnerMesh{v1, v2, v3});
}

void Object::move(const Vec3& movement) { transform_.translate(movement); }

void Object::scale(const Vec3& scale) { transform_.scale(scale); }

void Object::rotate(Angle angle, const Vec3& axis) {
	transform_.rotate(Rotation(angle, axis));
}

ConstMeshIterator Object::begin() const {
	return ConstMeshIterator(meshes_.cbegin(), *this);
}

ConstMeshIterator Object::end() const {
	return ConstMeshIterator(meshes_.cend(), *this);
}

// ProxyMesh

ProxyMesh::ProxyMesh(MeshCRef mesh, ObjectCRef object)
	: mesh_(mesh), object_(object) {}

Vec4 ProxyMesh::position(Index index) const {
	return (object_.get().transform_) *
		   (object_.get()
				.positions_[mesh_.get().vertices[index]]); // Affine transform *
														   // point
}

Color3f ProxyMesh::color(Index index) const {
	return object_.get().colors_[mesh_.get().vertices[index]];
}

// ConstMeshIterator

ConstMeshIterator::ConstMeshIterator(RawIterator iter, ObjectCRef object)
	: iter_(iter), object_(object) {}

ProxyMesh ConstMeshIterator::operator*() { return ProxyMesh(*iter_, object_); }

ConstMeshIterator& ConstMeshIterator::operator++() {
	++iter_;
	return *this;
}

ConstMeshIterator& ConstMeshIterator::operator--() {
	--iter_;
	return *this;
}

bool ConstMeshIterator::operator==(const ConstMeshIterator& other) const {
	return (iter_ == other.iter_) &&
		   (&(object_.get()) == &(other.object_.get()));
}

bool ConstMeshIterator::operator!=(const ConstMeshIterator& other) const {
	return !(*this == other);
}

} // namespace r3d
