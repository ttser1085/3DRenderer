#pragma once

#include "Inttypes/Inttypes.h"
#include "Linalg/LinalgBase.h"

namespace r3d {

class Camera {

	using SizePair = inttypes::SizePair;

	using Float = linalg::Float;
	using Angle = linalg::Angle;
	using Vec3 = linalg::Vec3;
	using Vec4 = linalg::Vec4;
	using Mat4 = linalg::Mat4;
	using Transform = linalg::AffineTransform;
	using Rotation = linalg::Rotation;

public:
	Camera(Vec3 pos, SizePair size, Float speed = kDefaultSpeed,
		   Float sensitivity = kDefaultSensitivity, Angle fovy = kDefaultFovy,
		   Float z_near = kDefaultZNear, Float z_far = kDefaultZFar,
		   Vec3 dir = -Vec3::UnitZ(), Vec3 up = Vec3::UnitY());

	Vec4 projection(const Vec4& pos) const;
	Vec4 lookAt(const Vec4& pos) const;

	void move(const Vec3& dir, Float dtime);
	void rotateYaw(Angle angle);
	void rotatePitch(Angle angle);

	SizePair targetSize() const;
	void resizeTarget(SizePair size);

private:
	void updateProjection();

	Transform look_at_;

	Float speed_;
	Float sensitivity_;

	SizePair target_size_;
	Angle fovy_;
	Float aspect_;
	Float z_near_;
	Float z_far_;

	Mat4 projection_;

	constexpr static Float kDefaultSpeed = 1.0f;
	constexpr static Float kDefaultSensitivity = 0.1f;
	constexpr static Float kDefaultZNear = 0.1f;
	constexpr static Float kDefaultZFar = 100.f;
	constexpr static Angle kDefaultFovy = M_PI_4; // 45 degrees
};

} // namespace r3d
