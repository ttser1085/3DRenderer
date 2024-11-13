#include "Model.h"

namespace r3d {

Model::Model(size_t frame_width, size_t frame_height) noexcept
	: current_frame_(frame_width, frame_height), frame_port_out_([this]() {
		  this->renderer_(this->current_frame_);
		  return this->current_frame_.data();
	  }) {}

void Model::attachFramePort(NSLibrary::CObserver<uint8_t*>* obs) {
	frame_port_out_.subscribe(obs);
}

void Model::startRender() { frame_port_out_.notify(); }

} // namespace r3d
