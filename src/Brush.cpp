#include "Brush.h"

namespace r3d {

Brush::Brush(Canvas canvas) : canvas_(canvas) {}

void Brush::drawPoint(const Vec2f& pos, const Color3f& color) {
	Vec2s real_pos = {
		static_cast<screen_size_t>(pos(0) * canvas_->getWidth()),
		static_cast<screen_size_t>(pos(1) * canvas_->getHeight())
	};

    canvas_->setColor(real_pos, Color3b::fromColor3f(color));
}

} // namespace r3d
