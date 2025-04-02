#pragma once

#include "Camera.h"
#include "Frame.h"
#include "Scene.h"

namespace r3d {

class Renderer {

	using Width = inttypes::Width;
	using Height = inttypes::Height;

public:
	Frame makeFrame(const Camera& camera, const Scene& scene) const;
};

} // namespace r3d
