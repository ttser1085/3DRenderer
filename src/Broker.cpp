#include "Broker.h"

namespace r3d {

void Broker::handle(CoreEvent event) {
	if (std::get_if<Update>(&event)) {
		append(std::move(event));
		flush();
	} else {
		append(std::move(event));
	}
}

} // namespace r3d
