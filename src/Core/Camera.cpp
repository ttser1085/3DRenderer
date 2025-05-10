#include "Camera.h"

#include "Linalg/Perspective.h"

namespace r3d {

Camera::Camera(Vec3 pos, SizePair size, Float speed, Float sensitivity,
			   Angle fovy, Float z_near, Float z_far, Vec3 dir, Vec3 up)
	: speed_(speed), sensitivity_(sensitivity), target_size_(size),
	  fovy_(fovy), z_near_(z_near), z_far_(z_far) {

	assert(z_far > z_near && "Invalid argument!");
	assert(z_near > 0.0f && "Invalid argument!");

	aspect_ = static_cast<Float>(size.x) / static_cast<Float>(size.y);
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

Vec4 Camera::projection(const Vec4& pos) const { return projection_ * pos; }

Vec4 Camera::lookAt(const Vec4& pos) const { return look_at_ * pos; }

void Camera::move(const Vec3& dir, Float dtime) {
	assert(lalg::approxEqual(dir.norm(), 1.0f) ||
		   lalg::approxEqual(dir.norm(), 0.0f));

	look_at_.pretranslate(-dir * dtime * speed_);
}

void Camera::rotateYaw(Angle angle) {
	look_at_.prerotate(Rotation(angle * sensitivity_, Vec3::UnitY()));
}

void Camera::rotatePitch(Angle angle) {
	look_at_.prerotate(Rotation(angle * sensitivity_, Vec3::UnitX()));
}

SizePair Camera::targetSize() const { return target_size_; }

void Camera::resizeTarget(SizePair size) {
	target_size_ = size;
	aspect_ = static_cast<Float>(size.x) / static_cast<Float>(size.y);
	updateProjection();
}

Angle Camera::fovy() const { return fovy_; }

std::vector<lalg::Plane> Camera::planes() const {
	using lalg::Plane;

	FrustumCorners cs = corners();

	return {
		Plane::Through(cs.ntl, cs.ntr, cs.nbr), // near
		Plane::Through(cs.ftr, cs.ftl, cs.fbl), // far
		Plane::Through(cs.ntr, cs.ntl, cs.ftl), // top
		Plane::Through(cs.nbl, cs.nbr, cs.fbr), // bottom
		Plane::Through(cs.nbr, cs.ntr, cs.fbr), // right
		Plane::Through(cs.ntl, cs.nbl, cs.fbl), // left
	};
}

Camera::FrustumCorners Camera::corners() const {
	Float h_near = 2.0f * std::tan(fovy_ * 0.5f) * z_near_;
	Float w_near = h_near * aspect_;
	Float h_far = 2.0f * std::tan(fovy_ * 0.5f) * z_far_;
	Float w_far = h_far * aspect_;

	auto cam2world = look_at_.inverse();

	Vec3 right = cam2world.linear().col(0).normalized();
	Vec3 up = cam2world.linear().col(1).normalized();
	Vec3 dir = -cam2world.linear().col(2).normalized();
	Vec3 pos = cam2world.translation();

	Vec3 fc = pos + dir * z_far_;
	Vec3 nc = pos + dir * z_near_;

	return FrustumCorners{
		nc + (up * h_near * 0.5f) - (right * w_near * 0.5f),
		nc + (up * h_near * 0.5f) + (right * w_near * 0.5f),
		nc - (up * h_near * 0.5f) - (right * w_near * 0.5f),
		nc - (up * h_near * 0.5f) + (right * w_near * 0.5f),
		fc + (up * h_far * 0.5f) - (right * w_far * 0.5f),
		fc + (up * h_far * 0.5f) + (right * w_far * 0.5f),
		fc - (up * h_far * 0.5f) - (right * w_far * 0.5f),
		fc - (up * h_far * 0.5f) + (right * w_far * 0.5f),
	};
}

void Camera::updateProjection() {
	projection_ = lalg::perspective(fovy_, aspect_, z_near_, z_far_);
}

} // namespace r3d
