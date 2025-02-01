#include "Brush.h"

namespace r3d {

Brush::Brush(Canvas&& canvas) : canvas_(std::move(canvas)) {}

void Brush::drawPoint(const Vec2& pos, const Color3f& color) {
	SizePair real_pos =
		SizePair{static_cast<Width>(pos(0) * canvas_.width()),
				 static_cast<Height>(pos(1) * canvas_.height())};

	canvas_.setColor(real_pos, Color3b::fromColor3f(color));
}

Brush::Canvas&& Brush::release() { return std::move(canvas_); }

} // namespace r3d
