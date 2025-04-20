#pragma once

#include "Frame.h"
#include "Linalg/Interpolation.h"
#include "Mesh.h"
#include "Test.h"

namespace r3d {

template<Test T>
class Drawer {
	using Vec2 = linalg::Vec2;

public:
	Drawer(Frame&& canvas, T&& test)
		: canvas_(std::move(canvas)),
		  canvas_size_(static_cast<Float>(canvas_.width()),
					   static_cast<Float>(canvas_.height())),
		  test_(std::move(test)) {}

	void drawLine(const Vertex& v1, const Vertex& v2) {
		using linalg::linearCombination, linalg::barycentric;

		SizePair pair1 = relativeToAbsolute(v1.pos.head<2>());
		SizePair pair2 = relativeToAbsolute(v2.pos.head<2>());

		if (test_(pair1, v1)) {
			canvas_.setColor(pair1, Color3b::fromColor3f(v1.color));
		}

		ScreenSize dx = std::abs(pair2.x - pair1.x);
		ScreenSize dy = std::abs(pair2.y - pair1.y);
		ScreenSize sx = pair2.x >= pair1.x ? 1 : -1;
		ScreenSize sy = pair2.y >= pair1.y ? 1 : -1;

		if (dy <= dx) {
			ScreenSize d = (dy << 1) - dx;
			ScreenSize d1 = (dy << 1);
			ScreenSize d2 = (dy - dx) << 1;

			for (ScreenSize x = pair1.x + sx, y = pair1.y, i = 0; i < dx;
				 ++i, x += sx) {
				if (d > 0) {
					d += d2;
					y += sy;
				} else {
					d += d1;
				}

				SizePair cur_pos = makeSizePair(x, y);
				Vec2 p = absoluteToRelative(cur_pos);
				Vec2 brc = barycentric(p, v1.pos.head<2>(), v2.pos.head<2>());

				assert(linalg::isCorrectBrc<2>(brc, p, v1.pos.head<2>(),
											   v2.pos.head<2>()));
				assert(linalg::isNormBrc(brc));
				assert(linalg::isInnerBrc(brc));

				Vertex v{linearCombination<Vec4>(brc, v1.pos, v2.pos),
						 linearCombination<Color3f>(brc, v1.color, v2.color)};

				if (test_(cur_pos, v)) {
					canvas_.setColor(cur_pos, Color3b::fromColor3f(v.color));
				}
			}
		} else {
			ScreenSize d = (dx << 1) - dy;
			ScreenSize d1 = (dx << 1);
			ScreenSize d2 = (dx - dy) << 1;

			for (ScreenSize x = pair1.x, y = pair1.y + sy, i = 0; i < dy;
				 ++i, y += sy) {
				if (d > 0) {
					d += d2;
					x += sx;
				} else {
					d += d1;
				}

				SizePair cur_pos = makeSizePair(x, y);
				Vec2 p = absoluteToRelative(cur_pos);
				Vec2 brc = barycentric(p, v1.pos.head<2>(), v2.pos.head<2>());

				assert(linalg::isCorrectBrc<2>(brc, p, v1.pos.head<2>(),
											   v2.pos.head<2>()));
				assert(linalg::isNormBrc(brc));
				assert(linalg::isInnerBrc(brc));

				Vertex v{linearCombination<Vec4>(brc, v1.pos, v2.pos),
						 linearCombination<Color3f>(brc, v1.color, v2.color)};

				if (test_(cur_pos, v)) {
					canvas_.setColor(cur_pos, Color3b::fromColor3f(v.color));
				}
			}
		}
	}

	void drawMesh(const Mesh& mesh) {
		drawLine(mesh.vertices[0], mesh.vertices[1]);
		drawLine(mesh.vertices[1], mesh.vertices[2]);
		drawLine(mesh.vertices[2], mesh.vertices[0]);
	}

	void fillMesh(const Mesh& mesh) {
		// TODO
	}

	Frame release() { return std::move(canvas_); }

private:
	// convert x: [-1.0f, 1.0f] --> [0, width]
	// convert y: [-1.0f, 1.0f] --> [height, 0]
	SizePair relativeToAbsolute(const Vec2& pos) const {
		return makeSizePair<float, float>(
			((pos(0) + 1.0f) / 2.0f) * (canvas_size_(0)),
			((-pos(1) + 1.0f) / 2.0f) * (canvas_size_(1)));
	}

	// convert x: [0, width] --> [-1.0f, 1.0f]
	// convert y: [height, 0] --> [-1.0f, 1.0f]
	Vec2 absoluteToRelative(SizePair pos) const {
		return Vec2(2.0f * static_cast<Float>(pos.x) / canvas_size_(0) - 1.0f,
					-2.0f * static_cast<Float>(pos.y) / canvas_size_(1) + 1.0f);
	}

	Frame canvas_;
	Vec2 canvas_size_;
	T test_;
};

} // namespace r3d
