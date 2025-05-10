#pragma once

#include "Inttypes/Inttypes.h"
#include "Linalg/LinalgBase.h"

namespace r3d {

using lalg::Float, lalg::Angle;
using lalg::Vec3, lalg::Vec4;

class Camera {
	using Transform = lalg::AffineTransform;
	using Rotation = lalg::Rotation;

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

	Angle fovy() const;

	std::vector<lalg::Plane> planes() const;

private:
	struct FrustumCorners {
		Vec3 ntl, ntr, nbl, nbr;
		Vec3 ftl, ftr, fbl, fbr;
	};

	FrustumCorners corners() const;

	void updateProjection();

	Transform look_at_;

	Vec3 pos_;
	Float speed_;
	Float sensitivity_;

	SizePair target_size_;
	Angle fovy_;
	Float aspect_;
	Float z_near_;
	Float z_far_;

	lalg::Mat4 projection_;

	constexpr static Float kDefaultSpeed = 1.0f;
	constexpr static Float kDefaultSensitivity = 0.5f;
	constexpr static Float kDefaultZNear = 0.1f;
	constexpr static Float kDefaultZFar = 20.f;
	constexpr static Angle kDefaultFovy = M_PI_4; // 45 degrees
};

} // namespace r3d
