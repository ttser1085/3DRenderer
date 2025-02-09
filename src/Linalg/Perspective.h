#pragma once

#include "LinalgBase.h"

namespace linalg {

Mat4 perspective(Angle fovy, Float aspect, Float z_near, Float z_far);

} // namespace linalg
