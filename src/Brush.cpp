#include "Brush.h"

namespace r3d {

Brush::Brush(Canvas&& canvas) : canvas_(std::move(canvas)) {}

void Brush::drawPoint(const Vec2f& pos, const Color3f& color) {
	Vec2s real_pos = {static_cast<screen_size_t>(pos(0) * canvas_.width()),
					  static_cast<screen_size_t>(pos(1) * canvas_.height())};

	canvas_.setColor(real_pos, Color3b::fromColor3f(color));
}

Brush::Canvas&& Brush::release() { return std::move(canvas_); }

} // namespace r3d
