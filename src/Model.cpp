#include "Model.h"

namespace r3d {

Model::Model(SizePair target_size_) : camera_(Vec3::Zero(), target_size_) {}

void Model::subscribe(FrameInput* obs) { frame_out_.subscribe(obs); }

void Model::renderFrame() {
	frame_out_.set(std::make_shared<const Frame>(
		std::move(renderer_.makeFrame(camera_, scene_))));
}

void Model::moveCamera(Vec3 dir, Float dtime) {
	camera_.move(dir, dtime);
}

} // namespace r3d
