#include "Model.h"

#include "Utils/Overloaded.h"

namespace r3d {

Model::Model(SizePair target_size_)
	: core_(target_size_), movement_dir_(Vec3::Zero()),
	  EventReceiver([this](const Events& events) { handle(events); }) {}

void Model::handle(const Events& events) {
	assert(!events.empty());
	assert(isTerminated(events.back())); // termination must be last

	for (const auto& event : events) {
		utils::Visit(
			event,
			[this](const Update& update) {
				core_.camera().move(movement_dir_.normalized(), update.dtime);
				movement_dir_ = Vec3::Zero();
				set(core_.renderFrame());
			},
			[this](const MoveCamera& move) { movement_dir_ += move.dir; },
			[this](const RotateCamera& rotate) {
				lalg::Angle yaw = core_.camera().fovy() * rotate.delta_yaw;
				lalg::Angle pitch = core_.camera().fovy() * rotate.delta_pitch;
				core_.camera().rotateYaw(yaw);
				core_.camera().rotatePitch(pitch);
			},
			[this](const BeginObject& begin) {
				core_.scene().beginObject(begin.pos, begin.rotation);
			},
			[this](const EndObject&) { core_.scene().endObject(); },
			[this](const AddVertex& add) {
				core_.scene().addVertex(add.vertex);
			},
			[this](const AddMesh& add) {
				core_.scene().addMesh(add.vertices[0], add.vertices[1],
									  add.vertices[2]);
			});
	}
}

} // namespace r3d
