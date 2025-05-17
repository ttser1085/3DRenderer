#pragma once

#include "Communication.h"
#include "CoreEvent.h"
#include "ModelEvent.h"

namespace r3d {

class MouseController {
public:
	MouseController()
		: input_([this](const MouseMoved& moved) {
			  output_.set(
				  RotateCamera{static_cast<lalg::Float>(moved.delta.x) /
								   static_cast<lalg::Float>(moved.win_size.x),
							   static_cast<lalg::Float>(moved.delta.y) /
								   static_cast<lalg::Float>(moved.win_size.y),
							   0.0});
		  }) {}

	ColdInput<MouseMoved>* input() { return &input_; }

	void subscribe(Input<RotateCamera>* input) { output_.subscribe(input); }

private:
	ColdInput<MouseMoved> input_;
	Output<RotateCamera> output_;
};

} // namespace r3d
