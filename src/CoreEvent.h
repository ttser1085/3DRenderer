#pragma once

#include "Linalg/LinalgBase.h"

#include <variant>

namespace r3d {

struct MoveCamera {
    linalg::Vec3 dir;
};

struct Update {
    linalg::Float dtime;
};

using CoreEvent = std::variant<MoveCamera, Update>;

} // namespace r3d
