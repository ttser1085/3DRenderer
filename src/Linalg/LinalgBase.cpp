#include "LinalgBase.h"

#include <cmath>

namespace lalg {

bool approxEqual(Float f1, Float f2, Float precision) {
	return std::abs(f2 - f1) <= precision;
}

Angle toRadians(Angle degrees) { return degrees * M_PI / 180.0f; }

Angle toDegrees(Angle radians) { return radians * 180.0f * M_1_PI; }

Vec4 homoNormalized(const Vec4& homo) {
	assert(!approxEqual(homo(3), 0.0f) && "Zero division error!");
	return homo / homo(3);
}

Vec4 homoNormalized(const Vec3& decart) {
	return Vec4{decart(0), decart(1), decart(2), 1.0f};
}

} // namespace lalg
