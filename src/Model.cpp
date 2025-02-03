#include "Model.h"

namespace r3d {

Model::Model(Width frame_width, Height frame_height)
	: renderer_(frame_width, frame_height) {}

void Model::attachFramePort(FrameInput* obs) { frame_out_.subscribe(obs); }

void Model::renderFrame() {
	frame_out_.set(
		std::make_shared<const Frame>(std::move(renderer_.makeFrame())));
}

} // namespace r3d
