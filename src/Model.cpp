#include "Model.h"

namespace r3d {

Model::Model(SizePair target_size_)
	: core_(target_size_), movement_dir_(Vec3::Zero()),
	  EventReceiver([this](const Events& events) { handle(events); }) {}

void Model::handle(const Events& events) {
	assert(!events.empty());
	assert(std::get_if<Update>(&events.back()));

	for (const auto& event : events) {
		if (const auto* update = std::get_if<Update>(&event)) {
			core_.camera().move(movement_dir_.normalized(), update->dtime);
			movement_dir_ = Vec3::Zero();
			set(core_.renderFrame());
		} else if (const auto* movement = std::get_if<MoveCamera>(&event)) {
			movement_dir_ += movement->dir;
		} else if (const auto* rotation = std::get_if<RotateCamera>(&event)) {
			linalg::Angle yaw = core_.camera().fovy() * rotation->delta_yaw;
			linalg::Angle pitch = core_.camera().fovy() * rotation->delta_pitch;

			core_.camera().rotateYaw(yaw);
			core_.camera().rotatePitch(pitch);
		}
	}
}

} // namespace r3d
