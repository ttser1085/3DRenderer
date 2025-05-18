#include "Core.h"

namespace r3d {

Frame Core::renderFrame() const {
	return renderer_.makeFrame(camera_, scene_);
}

Renderer& Core::renderer() { return renderer_; }

Camera& Core::camera() { return camera_; }

Scene& Core::scene() { return scene_; }

} // namespace r3d
