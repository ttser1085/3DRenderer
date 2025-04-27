#pragma once

#include "Broker.h"
#include "ModelEvent.h"

namespace r3d {

auto MouseController = [](Broker& broker, const MouseMoved& moved) {
	broker.handle(RotateCamera{static_cast<lalg::Float>(moved.delta.x) /
								   static_cast<lalg::Float>(moved.win_size.x),
							   static_cast<lalg::Float>(moved.delta.y) /
								   static_cast<lalg::Float>(moved.win_size.y),
							   0.0});
};

} // namespace r3d
