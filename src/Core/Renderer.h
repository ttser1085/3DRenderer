#pragma once

#include "Camera.h"
#include "Frame.h"
#include "Scene.h"

namespace r3d {

class Renderer {
public:
	enum class RenderMode {
		FULL,
		SKELETON,
		BORDERED,
	};

	Frame makeFrame(const Camera& camera, const Scene& scene) const;

	void setMode(RenderMode mode);

private:
	RenderMode mode_ = RenderMode::FULL;
};

} // namespace r3d
