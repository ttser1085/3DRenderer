#include "LinalgBase.h"

namespace linalg {

Vec3 fromHomogen(const Vec4& homo) {
	assert(homo(3) != 0 && "Zero division error!");
	return Vec3{homo(0) / homo(3), homo(1) / homo(3), homo(2) / homo(3)};
}

Vec4 toHomogen(const Vec3& vec) { return Vec4{vec(0), vec(1), vec(2), 1.0f}; }

bool approxEqual(Float x1, Float x2, Float eps) {
	return std::abs(x2 - x1) < eps;
}

} // namespace linalg
