#pragma once

#include "Communication.h"
#include "CoreEvent.h"

#include <Observer.h>

namespace r3d {

class Broker : public StreamOutput<CoreEvent>,
			   public ColdInput<MoveCamera, ByRef>,
			   public ColdInput<RotateCamera, ByRef>,
			   public ColdInput<Update, ByRef> {
public:
	using MoveReceiver = ColdInput<MoveCamera, ByRef>;
	using RotateReceiver = ColdInput<RotateCamera, ByRef>;
	using UpdateReceiver = ColdInput<Update, ByRef>;

	Broker();
};

} // namespace r3d
