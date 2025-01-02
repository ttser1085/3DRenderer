#include "Renderer.h"

namespace r3d {

// Renderer

Renderer::Renderer(Frame::Width target_width, Frame::Height target_height)
	: target_width_(target_width), target_height_(target_height) {}

FramePtr Renderer::makeFrame() {
	FramePtr frame = std::make_shared<Frame>(target_width_, target_height_);

	// render all objects

	return frame;
}

void Renderer::setTargetSize(Frame::Width target_width,
							 Frame::Height target_height) {
	target_width_ = target_width;
	target_height_ = target_height;
}

} // namespace r3d
