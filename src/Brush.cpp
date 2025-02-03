#include "Brush.h"
#include "Linalg/Interpolation.h"

namespace r3d {

Brush::Brush(Canvas&& canvas)
	: canvas_(std::move(canvas)),
	  canvas_size_(static_cast<float>(canvas_.width()),
				   static_cast<float>(canvas_.height())) {}

// convert x: [-1.0f, 1.0f] --> [0, width]
// convert y: [-1.0f, 1.0f] --> [height, 0]
Brush::SizePair Brush::relativeToAbsolute(const Vec2& pos) const {
	using inttypes::Width, inttypes::Height;
	return SizePair{
		static_cast<Width>(((pos(0) + 1.0f) / 2.0f) * (canvas_size_(0))),
		static_cast<Height>(((-pos(1) + 1.0f) / 2.0f) * (canvas_size_(1)))};
}

// convert x: [0, width] --> [-1.0f, 1.0f]
// convert y: [height, 0] --> [-1.0f, 1.0f]
Brush::Vec2 Brush::absoluteToRelative(const SizePair& pos) const {
	return Vec2(2.0f * static_cast<float>(pos.width) / canvas_size_(0) - 1.0f,
				-2.0f * static_cast<float>(pos.height) / canvas_size_(1) +
					1.0f);
}

void Brush::drawPixel(const SizePair& pos, const Color3f& color) {
	if ((pos.width < canvas_.width()) && (pos.height < canvas_.height())) {
		canvas_.setColor(pos, Color3b::fromColor3f(color));
	}
}

// Bresenhames algorithm
void Brush::drawLine(const Vec2& p1, const Color3f c1, const Vec2 p2,
					 Color3f c2) {
	using inttypes::makeSizePair, inttypes::sum, inttypes::diff, inttypes::abs;
	using inttypes::ScreenSize, inttypes::ScreenDiff;

	SizePair sp1 = relativeToAbsolute(p1);
	SizePair sp2 = relativeToAbsolute(p2);

	ScreenDiff dx = abs(diff(sp2.width, sp1.width));
	ScreenDiff dy = abs(diff(sp2.height, sp1.height));
	ScreenDiff sx = sp2.width >= sp1.width ? 1 : -1;
	ScreenDiff sy = sp2.height >= sp1.height ? 1 : -1;

	if (dy <= dx) {
		ScreenDiff d = (dy << 1) - dx;
		ScreenDiff d1 = (dy << 1);
		ScreenDiff d2 = (dy - dx) << 1;

		drawPixel(sp1, c1);

		for (ScreenSize x = sum(sp1.width, sx), y = sp1.height, i = 0; i <= dx;
			 ++i, x = sum(x, sx)) {
			if (d > 0) {
				d += d2;
				y += sy;
			} else {
				d += d1;
			}

			SizePair cur_pos = makeSizePair(x, y);
			Vec2 brc = linalg::barycentric(absoluteToRelative(cur_pos), p1, p2);
			drawPixel(cur_pos,
					  linalg::linearInterpolation<Color3f>(brc, c1, c2));
		}
	} else {
		ScreenDiff d = (dx << 1) - dy;
		ScreenDiff d1 = (dx << 1);
		ScreenDiff d2 = (dx - dy) << 1;

		drawPixel(sp1, c1);

		for (ScreenSize x = sp1.width, y = sum(sp1.height, sy), i = 0; i <= dy;
			 ++i, y = sum(y, sy)) {
			if (d > 0) {
				d += d2;
				x += sx;
			} else {
				d += d1;
			}

			SizePair cur_pos = makeSizePair(x, y);
			Vec2 brc = linalg::barycentric(absoluteToRelative(cur_pos), p1, p2);
			drawPixel(cur_pos,
					  linalg::linearInterpolation<Color3f>(brc, c1, c2));
		}
	}
}

void Brush::drawMesh(const Mesh& mesh) {
	drawLine(mesh.vertices[0].pos.head<2>(), mesh.vertices[0].color,
			 mesh.vertices[1].pos.head<2>(), mesh.vertices[1].color);
	drawLine(mesh.vertices[1].pos.head<2>(), mesh.vertices[1].color,
			 mesh.vertices[2].pos.head<2>(), mesh.vertices[2].color);
	drawLine(mesh.vertices[2].pos.head<2>(), mesh.vertices[2].color,
			 mesh.vertices[0].pos.head<2>(), mesh.vertices[0].color);
}

void Brush::fillMesh(const Mesh& mesh) {
	// TODO
}

Brush::Canvas&& Brush::release() { return std::move(canvas_); }

} // namespace r3d
