#pragma once

#include "Linalg/LinalgBase.h"

#include <variant>

namespace r3d {

struct MoveCamera {
    linalg::Vec3 dir;
};

struct RotateCamera {
    linalg::Float delta_yaw;
    linalg::Float delta_pitch;
    linalg::Float delta_roll;
};

struct Update {
    linalg::Float dtime;
};

using CoreEvent = std::variant<MoveCamera, RotateCamera, Update>;

} // namespace r3d
