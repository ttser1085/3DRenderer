#pragma once

#include "Communication.h"
#include "CoreEvent.h"
#include "ModelEvent.h"

namespace r3d {

class MouseController : public ColdReceiver<MouseMoved, ByRef>,
						public Sender<RotateCamera, ByRef> {
public:
	using Receiver = ColdReceiver<MouseMoved, ByRef>;

	MouseController()
		: Receiver([this](const MouseMoved& moved) {
			  set(RotateCamera{static_cast<lalg::Float>(moved.delta.x) /
								   static_cast<lalg::Float>(moved.win_size.x),
							   static_cast<lalg::Float>(moved.delta.y) /
								   static_cast<lalg::Float>(moved.win_size.y),
							   0.0});
		  }) {}
};

} // namespace r3d
