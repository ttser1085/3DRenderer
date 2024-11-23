#include "Model.h"

namespace r3d {

Model::Model(Frame::Width frame_width, Frame::Height frame_height)
	: current_frame_(std::make_shared<Frame>(frame_width, frame_height)) {}

void Model::attachFramePort(FrameObserver* obs) {
	frame_port_out_.subscribe(obs);
}

void Model::renderFrame() { 
	renderer_.render(current_frame_);
	frame_port_out_.set(current_frame_);
}

void Model::resizeFrame(const Vec2s& new_size) {
	current_frame_->changeSize(new_size);
}

} // namespace r3d
