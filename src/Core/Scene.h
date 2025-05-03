#pragma once

#include "Object.h"

namespace r3d {

class Scene {
public:
    Scene();
    
    const std::vector<Object>& objects() const;

    void beginObject(const Vec3& pos, const Vec3& angles);
    void endObject();

    void addVertex(const Vertex& vertex);
    void addMesh(Index v1, Index v2, Index v3);

private:
    void initObjects();

	std::vector<Object> objects_;
    bool started_ = false;

    // TODO: light sources
};

} // namespace r3d
