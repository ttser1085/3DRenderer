#pragma once

#include "Linalg/Interpolation.h"
#include "Mesh.h"

#include <concepts>

namespace r3d {

template<typename S>
concept Shader = requires(S shader, Mesh mesh, lalg::Vec3 brc) {
	{ shader(brc, mesh) } -> std::same_as<Vertex>;
};

template<typename S>
concept LineShader = requires(S shader, Vertex v1, Vertex v2, lalg::Vec2 brc) {
	{ shader(brc, v1, v2) } -> std::same_as<Vertex>;
};

class FullShader {
public:
	Vertex operator()(const Vec3& brc, const Mesh& mesh) {
		return Vertex{lalg::linearCombination<Vec4>(brc, mesh[0].pos,
													mesh[1].pos, mesh[2].pos),
					  lalg::linearCombination<Color3f>(
						  brc, mesh[0].color, mesh[1].color, mesh[2].color)};
	}
};

class OptimizedShader {
public:
	Vertex operator()(const Vec3& brc, const Mesh& mesh) {
		Float z = lalg::linearCombination<Float>(
			brc, mesh[0].pos(2), mesh[1].pos(2), mesh[2].pos(2));

		return Vertex{Vec4{0.0f, 0.0f, z, 1.0f}, mesh[0].color};
	}
};

class ConstColorShader {
public:
	explicit ConstColorShader(const Color3f& color) : color_(color) {}

	Vertex operator()(const Vec3& brc, const Mesh& mesh) {
		return Vertex{lalg::linearCombination<Vec4>(brc, mesh[0].pos,
													mesh[1].pos, mesh[2].pos),
					  color_};
	}

private:
	Color3f color_;
};

class FullLineShader {
public:
	Vertex operator()(const lalg::Vec2& brc, const Vertex& v1,
					  const Vertex& v2) {
		return Vertex{
			lalg::linearCombination<Vec4>(brc, v1.pos, v2.pos),
			lalg::linearCombination<Color3f>(brc, v1.color, v2.color)};
	}
};

class ConstColorLineShader {
public:
	explicit ConstColorLineShader(const Color3f& color) : color_(color) {}

	Vertex operator()(const lalg::Vec2& brc, const Vertex& v1,
					  const Vertex& v2) {
		return Vertex{lalg::linearCombination<Vec4>(brc, v1.pos, v2.pos),
					  color_};
	}

private:
	Color3f color_;
};

} // namespace r3d
