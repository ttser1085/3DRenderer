#pragma once

#include <Eigen/Core>

namespace r3d
{

// Vectors

using Vec2f = Eigen::Vector2f;
using Vec2d = Eigen::Vector2d;
using Vec2i = Eigen::Vector2i;
using Vec2s = Eigen::Vector2<size_t>;

using Vec3f = Eigen::Vector3f;
using Vec3d = Eigen::Vector3d;
using Vec3i = Eigen::Vector3i;
using Vec3s = Eigen::Vector3<size_t>;

using Vec4f = Eigen::Vector4f;
using Vec4d = Eigen::Vector4d;
using Vec4i = Eigen::Vector4i;
using Vec4s = Eigen::Vector4<size_t>;

// Matrices

using Mat3f = Eigen::Matrix3f;
using Mat3d = Eigen::Matrix3f;
using Mat3i = Eigen::Matrix3f;
using Mat3s = Eigen::Matrix3<size_t>;

using Mat4f = Eigen::Matrix4f;
using Mat4d = Eigen::Matrix4f;
using Mat4i = Eigen::Matrix4f;
using Mat4s = Eigen::Matrix4<size_t>;

} // namespace r3d
