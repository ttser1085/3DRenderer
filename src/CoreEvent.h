#pragma once

#include "Core/Renderer.h"
#include "Core/Vertex.h"

#include <variant>

namespace r3d {

struct MoveCamera {
	lalg::Vec3 dir;
};

struct RotateCamera {
	Float delta_yaw;
	Float delta_pitch;
	Float delta_roll;
};

struct Update {
	Float dtime;
};

using CoreEvent = std::variant<MoveCamera, RotateCamera, Update>;

inline bool isTerminated(const CoreEvent& event) {
	return std::holds_alternative<Update>(event);
}

} // namespace r3d
