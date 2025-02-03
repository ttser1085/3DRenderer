#pragma once

#include "Frame.h"
#include "Mesh.h"

namespace r3d {

class Brush {

	using Canvas = Frame;

	using SizePair = inttypes::SizePair;

	using Vec2 = linalg::Vec2;

public:
	explicit Brush(Canvas&& canvas);

	//void drawPoint(const Vec2& pos, const Color3f& color);
	void drawLine(const Vec2& p1, const Color3f c1, const Vec2 p2, Color3f c2);
	void drawMesh(const Mesh& mesh);
	void fillMesh(const Mesh& mesh);

	Canvas&& release();

private:
	SizePair relativeToAbsolute(const Vec2& pos) const;
	Vec2 absoluteToRelative(const SizePair& pos) const;

	void drawPixel(const SizePair& pos, const Color3f& color);

	Canvas canvas_;
	Vec2 canvas_size_;
};

} // namespace r3d
