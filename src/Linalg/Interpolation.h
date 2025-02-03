#pragma once

#include "LinalgBase.h"

namespace linalg {

Vec2 barycentric(const Vec2& p, const Vec2& a, const Vec2& b);

Vec3 barycentric(const Vec3& p, const Vec3& a, const Vec3& b, const Vec3& c);

template<typename R, int S, typename... Args>
R linearInterpolation(const Vec<S>& brc, Args&&... args) {
	static_assert(sizeof...(args) == S, "Invalid arguments number!");
	// static_assert((std::is_same_v<R, decltype(((brc[0] * args) + ...))>),
	// 			  "Invalid result type!");

	R result;
	int index = 0;
	((result = result + brc[index++] * args), ...);

	return result;
}

// Check barycentric coords:

template<int S, typename... Args>
bool isCorrectBrc(const Vec<S>& brc, const Vec<S> p, Args&&... args) {
	return approxEqual(p, linearInterpolation<Vec<S>>(brc, std::forward<Args>(args)...));
}

template<int S>
bool isNormBrc(const Vec<S>& brc) {
	return approxEqual(brc.sum(), 1.0f);
}

template<int S>
bool isInnerBrc(const Vec<S>& brc) {
	for (int index = 0; index < S; ++index) {
		if (brc[index] > 1.0f) {
			return false;
		}
	}

	return true;
}

} // namespace linalg
