#include "Object.h"

namespace r3d {

Object::Object() {}

ConstMeshIterator Object::begin() const { return ConstMeshIterator(meshes_.cbegin(), *this); }

ConstMeshIterator Object::end() const { return ConstMeshIterator(meshes_.cend(), *this); }

ProxyMesh::ProxyMesh(MeshCRef mesh, ObjectCRef object)
	: mesh_(mesh), object_(object) {}

Vec4f ProxyMesh::position(size_t index) const {
	return object_.get().positions_[mesh_.get().vertices[index]];
}

Color3f ProxyMesh::color(size_t index) const {
	return object_.get().colors_[mesh_.get().vertices[index]];
}

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
