#include "Broker.h"

namespace r3d {

void Broker::handle(CoreEvent event) {
	if (std::get_if<Update>(&event)) {
		set(std::move(event));
		flush();
	} else {
		set(std::move(event));
	}
}

} // namespace r3d
