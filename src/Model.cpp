#include "Model.h"

namespace r3d {

Model::Model(SizePair target_size_)
	: core_(target_size_), movement_dir_(Vec3::Zero()) {}

void Model::subscribe(FrameInput* obs) { frame_out_.subscribe(obs); }

void Model::Handle(std::vector<CoreEvent> events) {
	assert(!events.empty());
	assert(std::get_if<Update>(&events.back()));

	for (const auto& event : events) {
		if (const auto* update = std::get_if<Update>(&event)) {
			core_.moveCamera(movement_dir_.normalized(), update->dtime);
			movement_dir_ = Vec3::Zero();
			frame_out_.set(core_.renderFrame());
		} else if (const auto* movement = std::get_if<MoveCamera>(&event)) {
			movement_dir_ += movement->dir;
		}
	}
}

} // namespace r3d
