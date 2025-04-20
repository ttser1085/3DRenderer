#pragma once

#include "Camera.h"
#include "Frame.h"
#include "Scene.h"

namespace r3d {

class Renderer {
public:
	Frame makeFrame(const Camera& camera, const Scene& scene) const;
};

} // namespace r3d
