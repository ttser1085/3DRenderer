#pragma once

#include "Communication.h"
#include "CoreEvent.h"
#include "ModelEvent.h"

namespace r3d {

class TickController : public ColdReceiver<Tick, ByRef>,
					   public Sender<Update, ByRef> {
public:
	using Receiver = ColdReceiver<Tick, ByRef>;

	TickController()
		: Receiver([this](const Tick& tick) {
			  set(Update{tick.dtime.asSeconds()});
		  }) {}
};

} // namespace r3d
