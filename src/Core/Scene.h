#pragma once

#include "Object.h"

namespace r3d {

class Scene {
public:
    Scene();
    
    const std::vector<Object>& objects() const;

private:
    void initObjects();

	std::vector<Object> objects_;
    // TODO: light sources
};

} // namespace r3d
