#pragma once

#include "LinalgBase.h"

namespace lalg {

Vec2 barycentric(auto&& p, auto&& a, auto&& b) {
	Float dist_a = (p - a).norm();
	Float dist_b = (p - b).norm();

	return Vec2{dist_b, dist_a} / (dist_a + dist_b);
}

Vec3 barycentric(auto&& p, auto&& a, auto&& b, auto&& c) {
	auto v0 = b - a;
	auto v1 = c - a;
	auto v2 = p - a;

	Float d00 = v0.dot(v0);
	Float d01 = v0.dot(v1);
	Float d11 = v1.dot(v1);
	Float d20 = v2.dot(v0);
	Float d21 = v2.dot(v1);

	Float denom = d00 * d11 - d01 * d01;
	Float c1 = (d11 * d20 - d01 * d21) / denom;
	Float c2 = (d00 * d21 - d01 * d20) / denom;

	return Vec3{c1, c2, 1.0f - c1 - c2};
}

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
