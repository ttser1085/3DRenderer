#include "Perspective.h"

namespace linalg {

Mat4 perspective(Angle fovy, Float aspect, Float z_near, Float z_far) {
	assert(!approxEqual(z_near, z_far)  && "Zero division error!");

	Mat4 proj = Mat4::Zero();
	float tan_half_fovy = std::tan(fovy / 2.0f);

	proj.diagonal() << (1.0f / (aspect * tan_half_fovy)),
		(1.0f / tan_half_fovy), (-(z_far + z_near) / (z_far - z_near)), 0.0f;

	proj(2, 3) = -2.0f * z_far * z_near / (z_far - z_near);
	proj(3, 2) = -1.0f;

	return proj;
}

} // namespace linalg
