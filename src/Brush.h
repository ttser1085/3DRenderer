#pragma once

#include "Frame.h"
#include "Linalg/LinalgBase.h"

using linalg::Vec2;

namespace r3d {

class Brush {

	using Canvas = Frame;

public:
	explicit Brush(Canvas&& canvas);

	void drawPoint(const Vec2& pos, const Color3f& color);
	// void drawLine;
	// void drawMesh;
	// void fillMesh;

	Canvas&& release();

private:
	Canvas canvas_;
};

} // namespace r3d
