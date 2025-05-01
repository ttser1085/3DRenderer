#include "Broker.h"

namespace r3d {

void Broker::handle(CoreEvent event) {
	if (isTerminated(event)) {
		append(std::move(event));
		flush();
	} else {
		append(std::move(event));
	}
}

} // namespace r3d
