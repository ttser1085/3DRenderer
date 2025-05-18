#pragma once

#include "Object.h"

namespace r3d {

class Scene {
public:
    Scene();
    
    const std::vector<Object>& objects() const;

    void addObject(Object object);
    void addObjects(std::vector<Object> objects);
    void clear();

private:
	std::vector<Object> objects_;

    // TODO: light sources
};

} // namespace r3d
