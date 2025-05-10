#pragma once

#include "Frame.h"
#include "Linalg/Interpolation.h"
#include "Mesh.h"
#include "Shader.h"
#include "Test.h"

#include <iostream>

namespace r3d {

template<Shader S, LineShader LS, Test T>
class Drawer {
public:
	Drawer(Frame&& canvas, T&& test, S&& shader, LS&& line_shader)
		: canvas_(std::move(canvas)),
		  canvas_size_(static_cast<Float>(canvas_.width()),
					   static_cast<Float>(canvas_.height())),
		  test_(std::move(test)), shader_(std::move(shader)),
		  line_shader_(std::move(line_shader)) {}

	void drawLine(const Vertex& v1, const Vertex& v2) {
		using lalg::linearCombination, lalg::barycentric;
		using lalg::Vec2;

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

				Vertex v = line_shader_(brc, v1, v2);

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

				Vertex v = line_shader_(brc, v1, v2);

				if (test_(cur_pos, v)) {
					canvas_.setColor(cur_pos, Color3b::fromColor3f(v.color));
				}
			}
		}
	}

	void drawMesh(const Mesh& mesh) {
		drawLine(mesh[0], mesh[1]);
		drawLine(mesh[1], mesh[2]);
		drawLine(mesh[2], mesh[0]);
	}

	void fillMesh(const Mesh& mesh) {
		using lalg::linearCombination, lalg::barycentric;
		using lalg::Vec2;

		SizePair p1 = relativeToAbsolute(mesh[0].pos.head<2>());
		SizePair p2 = relativeToAbsolute(mesh[1].pos.head<2>());
		SizePair p3 = relativeToAbsolute(mesh[2].pos.head<2>());

		ScreenSize min_x = std::min(p1.x, std::min(p2.x, p3.x));
		ScreenSize max_x = std::max(p1.x, std::max(p2.x, p3.x));
		ScreenSize min_y = std::min(p1.y, std::min(p2.y, p3.y));
		ScreenSize max_y = std::max(p1.y, std::max(p2.y, p3.y));

		ScreenSize triangle_area = area(p1, p2, p3);

		for (ScreenSize y = min_y; y <= max_y; ++y) {
			for (ScreenSize x = min_x; x <= max_x; ++x) {
				SizePair cur_pos = makeSizePair(x, y);
				ScreenSize w1 = area(p2, p3, cur_pos);
				ScreenSize w2 = area(p3, p1, cur_pos);
				ScreenSize w3 = area(p1, p2, cur_pos);

				if ((w1 >= 0 && w2 >= 0 && w3 >= 0) ||
					(w1 <= 0 && w2 <= 0 && w3 <= 0)) {
					Vec3 brc{static_cast<Float>(w1) / triangle_area,
							 static_cast<Float>(w2) / triangle_area,
							 static_cast<Float>(w3) / triangle_area};

					Vertex v = shader_(brc, mesh);

					if (test_(cur_pos, v)) {
						canvas_.setColor(cur_pos,
										 Color3b::fromColor3f(v.color));
					}
				}
			}
		}
	}

	Frame release() { return std::move(canvas_); }

private:
	// convert x: [-1.0f, 1.0f] --> [0, width]
	// convert y: [-1.0f, 1.0f] --> [height, 0]
	SizePair relativeToAbsolute(const lalg::Vec2& pos) const {
		return makeSizePair<Float, Float>(
			((pos(0) + 1.0f) / 2.0f) * (canvas_size_(0)),
			((-pos(1) + 1.0f) / 2.0f) * (canvas_size_(1)));
	}

	// convert x: [0, width] --> [-1.0f, 1.0f]
	// convert y: [height, 0] --> [-1.0f, 1.0f]
	lalg::Vec2 absoluteToRelative(SizePair pos) const {
		return lalg::Vec2(
			2.0f * static_cast<Float>(pos.x) / canvas_size_(0) - 1.0f,
			-2.0f * static_cast<Float>(pos.y) / canvas_size_(1) + 1.0f);
	}

	Frame canvas_;
	lalg::Vec2 canvas_size_;
	T test_;
	S shader_;
	LS line_shader_;
};

} // namespace r3d
