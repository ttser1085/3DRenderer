#pragma once

#include "Inttypes.h"

#include <Eigen/Core>

namespace r3d {

// Vectors

using Vec2f = Eigen::Vector2f;
using Vec2d = Eigen::Vector2d;
using Vec2s = Eigen::Vector2<screen_size_t>;

using Vec3f = Eigen::Vector3f;
using Vec3d = Eigen::Vector3d;
using Vec3s = Eigen::Vector3<screen_size_t>;

using Vec4f = Eigen::Vector4f;
using Vec4d = Eigen::Vector4d;
using Vec4s = Eigen::Vector4<screen_size_t>;

// Matrices

using Mat3f = Eigen::Matrix3f;
using Mat3d = Eigen::Matrix3d;
using Mat3s = Eigen::Matrix3<screen_size_t>;

using Mat4f = Eigen::Matrix4f;
using Mat4d = Eigen::Matrix4d;
using Mat4s = Eigen::Matrix4<screen_size_t>;

} // namespace r3d
