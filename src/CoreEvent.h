#pragma once

#include "Linalg/LinalgBase.h"

#include <variant>

namespace r3d {

struct MoveCamera {
    lalg::Vec3 dir;
};

struct RotateCamera {
    lalg::Float delta_yaw;
    lalg::Float delta_pitch;
    lalg::Float delta_roll;
};

struct Update {
    lalg::Float dtime;
};

using CoreEvent = std::variant<MoveCamera, RotateCamera, Update>;

} // namespace r3d
