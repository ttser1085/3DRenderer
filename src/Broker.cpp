#include "Broker.h"

namespace r3d {
Broker::Broker()
	: MoveReceiver(
		  [this](const MoveCamera& event) { append(std::move(event)); }),
	  RotateReceiver([this](const RotateCamera& event) { append(std::move(event)); }),
	  UpdateReceiver([this](const Update& event) {
		  append(std::move(event));
		  flush();
	  }) {}

} // namespace r3d
