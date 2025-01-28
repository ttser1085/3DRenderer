#pragma once

#include "Object.h"

namespace r3d {

class Scene {
public:
    std::vector<Object>& objects();
    const std::vector<Object>& objects() const;

private:
	std::vector<Object> objects_;
    // TODO: light sources
};

} // namespace r3d
