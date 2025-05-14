#pragma once

#include "Communication.h"
#include "CoreEvent.h"

#include <Observer.h>

namespace r3d {

class Broker : public StreamSender<CoreEvent>,
			   public ColdReceiver<MoveCamera, ByRef>,
			   public ColdReceiver<RotateCamera, ByRef>,
			   public ColdReceiver<Update, ByRef> {
public:
	using MoveReceiver = ColdReceiver<MoveCamera, ByRef>;
	using RotateReceiver = ColdReceiver<RotateCamera, ByRef>;
	using UpdateReceiver = ColdReceiver<Update, ByRef>;

	Broker();
};

} // namespace r3d
