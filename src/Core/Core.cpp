#include "Core.h"

namespace r3d {

r3d::Core::Core(SizePair target_size_)
	: camera_(Vec3::Zero(), target_size_) {}

FrozenFrame Core::renderFrame() const {
	return std::make_shared<Frame>(renderer_.makeFrame(camera_, scene_));
}

Camera& Core::camera() {
	return camera_;
}

Scene& Core::scene() {
	return scene_;
}

} // namespace r3d
