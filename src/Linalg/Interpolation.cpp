#include "Interpolation.h"

namespace linalg {

Vec2 barycentric(const Vec2& p, const Vec2& a, const Vec2& b) {
	float dist_a = (p - a).norm();
	float dist_b = (p - b).norm();

	return Vec2{dist_b, dist_a} / (dist_a + dist_b);
}

Vec3 barycentric(const Vec3& p, const Vec3& a, const Vec3& b, const Vec3& c) {
	Vec3 v0 = b - a;
	Vec3 v1 = c - a;
	Vec3 v2 = p - a;

	float d00 = v0.dot(v0);
	float d01 = v0.dot(v1);
	float d11 = v1.dot(v1);
	float d20 = v2.dot(v0);
	float d21 = v2.dot(v1);

	float denom = d00 * d11 - d01 * d01;
	float c1 = (d11 * d20 - d01 * d21) / denom;
	float c2 = (d00 * d21 - d01 * d20) / denom;

	return Vec3{c1, c2, 1.0f - c1 - c2};
}

} // namespace linalg
