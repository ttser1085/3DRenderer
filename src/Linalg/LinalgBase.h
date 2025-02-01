#pragma once

#include <Eigen/Core>
#include <Eigen/Geometry>

namespace linalg {

// Vectors

template<int S>
using Vec = Eigen::Vector<float, S>;

using Vec2 = Vec<2>;
using Vec3 = Vec<3>;
using Vec4 = Vec<4>;

// Matrices

template<int S>
using Mat = Eigen::Matrix<float, S, S>;

using Mat3 = Mat<3>;
using Mat4 = Mat<4>;

// Angle

using Angle = float; // in radians

// Line

using Line = Eigen::ParametrizedLine<float, 3>;

// Plane

using Plane = Eigen::Hyperplane<float, 3>;

// Transforms

using Rotation = Eigen::AngleAxisf;
using AffineTransform = Eigen::Affine3f;

// casts

Vec3 fromHomogen(const Vec4&);
Vec4 toHomogen(const Vec3&);

// compare floating point vectors
// compare only objects with float32 scalar type

constexpr float kDefaultEps = 1e-5f;

bool approxEqual(float, float, float eps = kDefaultEps);

template<int S>
bool approxEqual(const Vec<S>& v1, const Vec<S>& v2, float eps = kDefaultEps) {
	return approxEqual((v2 - v1).sum(), 0.0f, eps);
}

template<int S>
bool approxEqual(const Mat<S>& m1, const Mat<S>& m2, float eps = kDefaultEps) {
	return approxEqual((m2 - m1).sum(), 0.0f, eps);
}

} // namespace linalg
