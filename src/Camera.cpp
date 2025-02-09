#include "Camera.h"

#include "Linalg/Perspective.h"

namespace r3d {

Camera::Camera(Vec3 pos, SizePair size, Float speed, Float sensitivity,
			   Angle fovy, Float z_near, Float z_far, Vec3 dir, Vec3 up)
	: speed_(speed), sensitivity_(sensitivity), target_size_(size), fovy_(fovy),
	  z_near_(z_near), z_far_(z_far) {

	assert(z_far > z_near && "Invalid argument!");
	assert(z_near > 0.0f && "Invalid argument!");

	aspect_ = static_cast<Float>(size.x) / size.y;
	updateProjection();

	dir.normalize();
	up.normalize();
	Vec3 right = dir.cross(up).normalized();
	look_at_ = Transform::Identity();
	look_at_.linear().row(0) << right(0), right(1), right(2);
	look_at_.linear().row(1) << up(0), up(1), up(2);
	look_at_.linear().row(2) << -dir(0), -dir(1), -dir(2);

	look_at_.pretranslate(pos);
}

Camera::Vec4 Camera::projection(const Vec4& pos) const {
	return projection_ * pos;
}

Camera::Vec4 Camera::lookAt(const Vec4& pos) const { return look_at_ * pos; }

void Camera::move(const Vec3& dir, Float dtime) {
	assert(linalg::approxEqual(dir.norm(), 1.0f) ||
		   linalg::approxEqual(dir.norm(), 0.0f));
	look_at_.translate(-dir * dtime * speed_);
}

void Camera::rotateYaw(Angle angle) {
	look_at_.rotate(Rotation(angle * sensitivity_, Vec3::UnitY()));
}

void Camera::rotatePitch(Angle angle) {
	look_at_.rotate(Rotation(angle * sensitivity_, Vec3::UnitX()));
}

Camera::SizePair Camera::targetSize() const { return target_size_; }

void Camera::resizeTarget(SizePair size) {
	target_size_ = size;
	aspect_ = static_cast<Float>(size.x) / size.y;
	updateProjection();
}

void Camera::updateProjection() {
	projection_ = linalg::perspective(fovy_, aspect_, z_near_, z_far_);
}

} // namespace r3d
