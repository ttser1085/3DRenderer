#include "Renderer.h"

#include "Brush.h"

namespace r3d {

// Renderer

Renderer::Renderer(Width target_width, Height target_height)
	: target_width_(target_width), target_height_(target_height) {}

FramePtr Renderer::makeFrame() const {
	FramePtr frame = std::make_shared<Frame>(target_width_, target_height_);
	frame->clear(kBlack3b);

	Brush brush(frame);

	for (const auto& object : scene_.objects()) {
		for (auto mesh : object) {
			// TODO:
		}
	}

	return frame;
}

void Renderer::setTargetSize(Width target_width, Height target_height) {
	target_width_ = target_width;
	target_height_ = target_height;
}

} // namespace r3d
