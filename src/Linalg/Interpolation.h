#pragma once

#include "LinalgBase.h"

namespace linalg {

Vec2 barycentric(const Vec2& p, const Vec2& a, const Vec2& b);

Vec3 barycentric(const Vec3& p, const Vec3& a, const Vec3& b, const Vec3& c);

template<typename R, int S, typename First, typename... Args>
R linearInterpolation(const Vec<S>& brc, First first, Args&&... args) {
	static_assert(S >= 1, "Invalid arguments number!");
	static_assert(sizeof...(args) == S - 1, "Invalid arguments number!");

	R result = brc(0) * first;
	int index = 1;
	((result = result + brc(index++) * args), ...);

	return result;
}

// Check barycentric coords:

template<int S, typename... Args>
bool isCorrectBrc(const Vec<S>& brc, const Vec<S> p, Args&&... args) {
	static constexpr Float kPrecision = 2.25f;
	return p.isApprox(
		linearInterpolation<Vec<S>>(brc, std::forward<Args>(args)...),
		kPrecision);
}

template<int S>
bool isNormBrc(const Vec<S>& brc) {
	static constexpr Float kPrecision = 1e-5f;
	return Vec<1>{brc.sum()}.isOnes(kPrecision);
}

template<int S>
bool isInnerBrc(const Vec<S>& brc) {
	static constexpr Float kPrecision = 1.5f;
	return brc.isMuchSmallerThan(1.0f, kPrecision);
}

} // namespace linalg
