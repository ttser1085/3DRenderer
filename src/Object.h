#pragma once

#include "Color.h"
#include "Linalg.h"

#include <functional>

namespace r3d {

class ConstMeshIterator;

class Object {
    friend class ProxyMesh;
    friend class ConstMeshIterator;

public:
    Object();

    ConstMeshIterator begin() const;
    ConstMeshIterator end() const;

private:
    struct Mesh {
        size_t vertices[3];
    };

    std::vector<Vec4f> positions_;
    std::vector<Color3f> colors_;
    // std::vector<Vec3f> normals;

    std::vector<Mesh> meshes_;
};

class ProxyMesh {
    friend class ConstMeshIterator;

    using MeshCRef = std::reference_wrapper<const Object::Mesh>;
    using ObjectCRef = std::reference_wrapper<const Object>;

public:
    Vec4f position(size_t index) const;
    Color3f color(size_t index) const;

private:
    MeshCRef mesh_;
	ObjectCRef object_;

    ProxyMesh(MeshCRef mesh, ObjectCRef object);
};

class ConstMeshIterator {
    friend class Object;

    using RawIterator = std::vector<Object::Mesh>::const_iterator;
    using ObjectCRef = std::reference_wrapper<const Object>;

public:
    ProxyMesh operator*();
    
    ConstMeshIterator& operator++();
    ConstMeshIterator& operator--();

    bool operator==(const ConstMeshIterator& other) const;
    bool operator!=(const ConstMeshIterator& other) const ;

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
