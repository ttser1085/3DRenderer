#include "Renderer.h"

#include "Brush.h"

namespace r3d {

// Renderer

Renderer::Renderer(Width target_width, Height target_height)
	: target_width_(target_width), target_height_(target_height) {}

Frame Renderer::makeFrame() const {
	Frame frame(target_width_, target_height_);
	frame.clear(kBlue3b);

	Brush brush(std::move(frame));

	for (const auto& object : scene_.objects()) {
		for (auto mesh : object) {
			// TODO:
		}
	}

	return brush.release();
}

void Renderer::setTargetSize(Width target_width, Height target_height) {
	target_width_ = target_width;
	target_height_ = target_height;
}

} // namespace r3d
