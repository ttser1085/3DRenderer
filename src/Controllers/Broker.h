#pragma once

#include "Communication.h"
#include "Messages/Core.h"

namespace r3d {

class Broker {
public:
	Broker();

	ColdInput<MoveCamera>* moveInput();
	ColdInput<RotateCamera>* rotateInput();
	ColdInput<Update>* updateInput();

	void subscribe(StreamInput<CoreEvent>* input);

private:
	StreamOutput<CoreEvent> output_;
	ColdInput<MoveCamera> move_input_;
	ColdInput<RotateCamera> rotate_input_;
	ColdInput<Update> update_input_;
};

} // namespace r3d
