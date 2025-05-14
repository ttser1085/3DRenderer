#include "Core.h"

namespace r3d {

FrozenFrame Core::renderFrame() const {
	return std::make_shared<Frame>(renderer_.makeFrame(camera_, scene_));
}

Renderer& Core::renderer() { return renderer_; }

Camera& Core::camera() { return camera_; }

Scene& Core::scene() { return scene_; }

} // namespace r3d
