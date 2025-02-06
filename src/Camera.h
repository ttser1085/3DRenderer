#pragma once

#include "Inttypes/Inttypes.h"
#include "Linalg/LinalgBase.h"

namespace r3d {

class Camera {

	using SizePair = inttypes::SizePair;

	using Float = linalg::Float;
	using Angle = linalg::Angle;
	using Mat4 = linalg::Mat4;

public:
	Camera(SizePair size, Angle fovy, Float z_near, Float z_far);

	const Mat4& projection() const;

    SizePair targetSize() const;
	void resizeTarget(SizePair size);

private:
	void updateProjection();

	SizePair target_size_;

	Angle fovy_;
	Float aspect_;
	Float z_near_;
	Float z_far_;

	Mat4 projection_;
};

} // namespace r3d
