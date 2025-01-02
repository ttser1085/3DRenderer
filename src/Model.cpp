#include "Model.h"

namespace r3d {

Model::Model(Frame::Width frame_width, Frame::Height frame_height)
	: renderer_(frame_width, frame_height) {}

void Model::attachFramePort(FrameObserver* obs) {
	frame_port_out_.subscribe(obs);
}

void Model::renderFrame() {
	frame_port_out_.set(renderer_.makeFrame());
}

void Model::resizeFrame(Frame::Width new_width, Frame::Height new_height) {
	renderer_.setTargetSize(new_width, new_height);
}

} // namespace r3d
