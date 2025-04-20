#pragma once

#include "Communication.h"
#include "CoreEvent.h"

#include <Observer.h>

namespace r3d {

class Broker : public StreamSender<CoreEvent> {
public:
	void handle(CoreEvent event);
};

} // namespace r3d
