#pragma once

#include "LinalgBase.h"

namespace linalg {

template<int S>
bool isNormBrc(const Vec<S>& vec) {
	return approxEqual(vec.sum(), 1.0f);
}

template<int S>
bool isInnerBrc(const Vec<S>& vec) {
	int index = 0;
	return ((vec[index++] <= 1.0f) || ...);
}

Vec2 Barycentric(const Vec2& p, const Vec2& a, const Vec2& b);

Vec3 Barycentric(const Vec3& p, const Vec3& a, const Vec3& b, const Vec3& c);

template<int S, typename R, typename... Args>
R Interpolation(const Vec<S>& brc, Args&&... args) {
	static_assert(sizeof...(args) == S, "Invalid arguments number!");
	static_assert((std::is_same_v<R, decltype(((brc[0] * args) + ...))>),
				  "Invalid result type!");

	R result;
	int index = 0;
	((result += brc[index++] * args), ...);

	return result;
}

} // namespace linalg
