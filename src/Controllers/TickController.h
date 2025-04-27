#include "Broker.h"
#include "ModelEvent.h"

namespace r3d {

auto TickController = [](Broker& broker, const Tick& tick) {
	broker.handle(Update{tick.dtime.asSeconds()});
};

} // namespace r3d
