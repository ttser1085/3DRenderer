#pragma once

#include <Eigen/Core>
#include <Eigen/Geometry>

namespace linalg {

// Float

using Float = float; // float32 or float64

// Vectors

template<int S>
using Vec = Eigen::Vector<Float, S>;

using Vec2 = Vec<2>;
using Vec3 = Vec<3>;
using Vec4 = Vec<4>;

// Matrices

template<int S>
using Mat = Eigen::Matrix<Float, S, S>;

using Mat3 = Mat<3>;
using Mat4 = Mat<4>;

// Angle

using Angle = Float; // in radians

// Line

using Line = Eigen::ParametrizedLine<Float, 3>;

// Plane

using Plane = Eigen::Hyperplane<Float, 3>;

// Transforms

using Rotation = Eigen::AngleAxisf;
using AffineTransform = Eigen::Affine3f;

// casts

Vec3 fromHomogen(const Vec4&);
Vec4 toHomogen(const Vec3&);

// compare floating point vectors
// compare only objects with float32 scalar type

constexpr Float kDefaultEps = 1e-5f;

bool approxEqual(Float, Float, Float eps = kDefaultEps);

template<int S>
bool approxEqual(const Vec<S>& v1, const Vec<S>& v2, Float eps = kDefaultEps) {
	return approxEqual((v2 - v1).sum(), 0.0f, eps);
}

template<int S>
bool approxEqual(const Mat<S>& m1, const Mat<S>& m2, Float eps = kDefaultEps) {
	return approxEqual((m2 - m1).sum(), 0.0f, eps);
}

} // namespace linalg
