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

struct BeginObject {
	Vec3 pos;
	Vec3 rotation;
};

struct EndObject {};

struct AddVertex {
	Vertex vertex;
};

struct AddMesh {
	Index vertices[3];
};

struct SetRenderMode {
	Renderer::RenderMode mode;
};

using CoreEvent = std::variant<MoveCamera, RotateCamera, Update, BeginObject,
							   EndObject, AddVertex, AddMesh, SetRenderMode>;

inline bool isTerminated(const CoreEvent& event) {
	return std::holds_alternative<Update>(event) ||
		   std::holds_alternative<EndObject>(event) ||
		   std::holds_alternative<SetRenderMode>(event);
}

} // namespace r3d
