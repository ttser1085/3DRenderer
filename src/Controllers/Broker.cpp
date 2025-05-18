#include "Broker.h"

namespace r3d {
Broker::Broker()
	: move_input_([this](const MoveCamera& event) {
		  output_.append(std::move(event));
	  }),
	  rotate_input_([this](const RotateCamera& event) {
		  output_.append(std::move(event));
	  }),
	  update_input_([this](const Update& event) {
		  output_.append(std::move(event));
		  output_.flush();
	  }) {}

ColdInput<MoveCamera>* Broker::moveInput() { return &move_input_; }

ColdInput<RotateCamera>* Broker::rotateInput() { return &rotate_input_; }

ColdInput<Update>* Broker::updateInput() { return &update_input_; }

void Broker::subscribe(StreamInput<CoreEvent>* input) {
	output_.subscribe(input);
}

} // namespace r3d
