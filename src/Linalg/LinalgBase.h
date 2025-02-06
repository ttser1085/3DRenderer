#pragma once

#include <Eigen/Core>
#include <Eigen/Geometry>

namespace linalg {

// Float

using Float = float; // float32 or float64

constexpr Float kDefaultPrecision = 1e-5;
bool approxEqual(Float f1, Float f2, Float precision = kDefaultPrecision);

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

using Angle = Float;

// Line

using Line = Eigen::ParametrizedLine<Float, 3>;

// Plane

using Plane = Eigen::Hyperplane<Float, 3>;

// Transforms

using Rotation = Eigen::AngleAxisf;
using AffineTransform = Eigen::Affine3f;

// casts

Angle toRadians(Angle degrees);
Angle toDegrees(Angle radians);

Vec4 homoNormalized(const Vec4& homo);

} // namespace linalg
