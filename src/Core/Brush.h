#pragma once

#include "Frame.h"
#include "Mesh.h"
#include "Test.h"

namespace r3d {

class Brush {

	using Canvas = Frame;

	using SizePair = inttypes::SizePair;
	using DiffPair = inttypes::DiffPair;

	using Vec2 = linalg::Vec2;

public:
	explicit Brush(Canvas&& canvas);

	void drawLine(const Vertex& v1, const Vertex& v2);
	void drawMesh(const Mesh& mesh);
	void fillMesh(const Mesh& mesh);

	Canvas release();

private:
	// SizePair relativeToAbsolute(const Vec2& pos) const;
	DiffPair relativeToAbsolute(const Vec2& pos) const;
	// Vec2 absoluteToRelative(SizePair pos) const;

	Vec2 absoluteToRelative(DiffPair pos) const;

	// void drawPixel(SizePair pos, const Color3f& color);
	void drawPixel(DiffPair pos, const Color3f& color);

	Canvas canvas_;
	Vec2 canvas_size_;
	DepthTest depth_test_;
};

} // namespace r3d
