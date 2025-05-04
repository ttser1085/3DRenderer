#pragma once

#include "LinalgBase.h"

namespace lalg {

Vec2 barycentric(const Vec2& p, const Vec2& a, const Vec2& b);

Vec3 barycentric(const Vec2& p, const Vec2& a, const Vec2& b, const Vec2& c);

template<Linear R, int Dim, Linear First, Linear... Args>
R linearCombination(const Vec<Dim>& brc, First&& first, Args&&... args) {
	static_assert(Dim >= 1, "Invalid arguments number!");
	static_assert(sizeof...(args) == Dim - 1, "Invalid arguments number!");

	R result = brc(0) * first;
	int index = 1;
	((result = result + brc(index++) * args), ...);

	return result;
}

// Check barycentric coords:

template<int S, Linear R, Linear... Args>
bool isCorrectBrc(const Vec<S>& brc, const R& p, Args&&... args) {
	static constexpr Float kPrecision = 0.05f;
	return approxEqual(
		p, linearCombination<R>(brc, std::forward<Args>(args)...), kPrecision);
}

template<int S>
bool isNormBrc(const Vec<S>& brc) {
	return approxEqual(brc.sum(), 1.0f);
}

template<int S>
bool isInnerBrc(const Vec<S>& brc) {
	static constexpr Float kPrecision = 1.05f;
	return brc.isMuchSmallerThan(1.0f, kPrecision);
}

} // namespace lalg
