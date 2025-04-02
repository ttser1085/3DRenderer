#include "Brush.h"
#include "Inttypes/Inttypes.h"
#include "Linalg/Interpolation.h"

namespace r3d {

Brush::Brush(Canvas&& canvas)
	: canvas_(std::move(canvas)),
	  canvas_size_(static_cast<Float>(canvas_.width()),
				   static_cast<Float>(canvas_.height())) {}

// convert x: [-1.0f, 1.0f] --> [0, width]
// convert y: [-1.0f, 1.0f] --> [height, 0]
Brush::DiffPair Brush::relativeToAbsolute(const Vec2& pos) const {
	return inttypes::makeDiffPair<float, float>(
		((pos(0) + 1.0f) / 2.0f) * (canvas_size_(0)),
		((-pos(1) + 1.0f) / 2.0f) * (canvas_size_(1)));
}

// convert x: [0, width] --> [-1.0f, 1.0f]
// convert y: [height, 0] --> [-1.0f, 1.0f]
Brush::Vec2 Brush::absoluteToRelative(DiffPair pos) const {
	return Vec2(2.0f * static_cast<Float>(pos.x) / canvas_size_(0) - 1.0f,
				-2.0f * static_cast<Float>(pos.y) / canvas_size_(1) + 1.0f);
}

void Brush::drawPixel(DiffPair pos, const Color3f& color) {
	if ((pos.x >= 0) && (pos.y >= 0)) {
		SizePair sp = inttypes::toSizePair(pos);
		if ((sp.x < canvas_.width()) && (sp.y < canvas_.height())) {
			canvas_.setColor(sp, Color3b::fromColor3f(color));
		}
	}
}

// Bresenhames algorithm
void Brush::drawLine(const Vec2& p1, const Color3f& c1, const Vec2& p2,
					 const Color3f& c2) {
	using inttypes::ScreenSize, inttypes::ScreenDiff, inttypes::DiffPair;

	DiffPair pair1 = relativeToAbsolute(p1);
	DiffPair pair2 = relativeToAbsolute(p2);

	drawPixel(pair1, c1);

	ScreenDiff dx = std::abs(pair2.x - pair1.x);
	ScreenDiff dy = std::abs(pair2.y - pair1.y);
	ScreenDiff sx = pair2.x >= pair1.x ? 1 : -1;
	ScreenDiff sy = pair2.y >= pair1.y ? 1 : -1;

	if (dy <= dx) {
		ScreenDiff d = (dy << 1) - dx;
		ScreenDiff d1 = (dy << 1);
		ScreenDiff d2 = (dy - dx) << 1;

		drawPixel(pair1, c1);

		for (ScreenDiff x = pair1.x + sx, y = pair1.y, i = 0; i < dx;
			 ++i, x += sx) {
			if (d > 0) {
				d += d2;
				y += sy;
			} else {
				d += d1;
			}

			DiffPair cur_pos = inttypes::makeDiffPair(x, y);
			Vec2 p = absoluteToRelative(cur_pos);
			Vec2 brc = linalg::barycentric(p, p1, p2);

			assert(linalg::isCorrectBrc<2>(brc, p, p1, p2));
			assert(linalg::isNormBrc(brc));
			assert(linalg::isInnerBrc(brc));

			drawPixel(cur_pos,
					  linalg::linearInterpolation<Color3f>(brc, c1, c2));
		}
	} else {
		ScreenDiff d = (dx << 1) - dy;
		ScreenDiff d1 = (dx << 1);
		ScreenDiff d2 = (dx - dy) << 1;

		drawPixel(pair1, c1);

		for (ScreenDiff x = pair1.x, y = pair1.y + sy, i = 0; i < dy;
			 ++i, y += sy) {
			if (d > 0) {
				d += d2;
				x += sx;
			} else {
				d += d1;
			}

			DiffPair cur_pos = inttypes::makeDiffPair(x, y);
			Vec2 p = absoluteToRelative(cur_pos);
			Vec2 brc = linalg::barycentric(p, p1, p2);

			assert(linalg::isCorrectBrc<2>(brc, p, p1, p2));
			assert(linalg::isNormBrc(brc));
			assert(linalg::isInnerBrc(brc));

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

Brush::Canvas Brush::release() { return std::move(canvas_); }

} // namespace r3d
