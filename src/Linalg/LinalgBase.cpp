#include "LinalgBase.h"

#include <cmath>

namespace linalg {

bool approxEqual(Float f1, Float f2, Float precision) {
	return Vec<1>(f1).isApproxToConstant(f2, precision);
}

Angle toRadians(Angle degrees) { return degrees * M_PI / 180.0f; }

Angle toDegrees(Angle radians) { return radians * 180.0f * M_1_PI; }

Vec4 homoNormalized(const Vec4& homo) {
	assert(!approxEqual(homo(3), 0.0f)  && "Zero division error!");
	return homo / homo(3);
}

} // namespace linalg
