#include "Camera.h"

#include "Linalg/Perspective.h"

namespace r3d {

Camera::Camera(SizePair size, Angle fovy, Float z_near, Float z_far)
	: target_size_(size), fovy_(fovy), z_near_(z_near), z_far_(z_far) {
	aspect_ = static_cast<Float>(size.width) / size.height;
	updateProjection();
}

const Camera::Mat4& Camera::projection() const { return projection_; }

Camera::SizePair Camera::targetSize() const { return target_size_; }

void Camera::resizeTarget(SizePair size) {
	target_size_ = size;
	aspect_ = static_cast<Float>(size.width) / size.height;
	updateProjection();
}

void Camera::updateProjection() {
	projection_ = linalg::perspective(fovy_, aspect_, z_near_, z_far_);
}

} // namespace r3d
