#include "Model.h"

namespace r3d {

Model::Model(SizePair target_size_)
	: camera_(target_size_, linalg::toRadians(45.0f), 0.1, 100.0f) {}

void Model::attachFramePort(FrameInput* obs) { frame_out_.subscribe(obs); }

void Model::renderFrame() {
	frame_out_.set(std::make_shared<const Frame>(
		std::move(renderer_.makeFrame(camera_, scene_))));
}

} // namespace r3d
