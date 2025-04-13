#include "Broker.h"

namespace r3d {

void Broker::handle(CoreEvent&& event) {
	events_.emplace_back(std::move(event));

	if (std::get_if<Update>(&events_.back())) {
		output_.set(std::exchange(events_, {}));
	}
}

void Broker::subscribe(Input* input) { output_.subscribe(input); }

} // namespace r3d
