#pragma once

#include "Communication.h"
#include "CoreEvent.h"
#include "ModelEvent.h"

namespace r3d {

class TickController {
public:
	TickController()
		: input_([this](const Tick& tick) {
			  output_.set(Update{tick.dtime.asSeconds()});
		  }) {}

	ColdInput<Tick>* input() { return &input_; }

	void subscribe(Input<Update>* input) {
		output_.subscribe(input);
	}

private:
	ColdInput<Tick> input_;
	Output<Update> output_;
};

} // namespace r3d
