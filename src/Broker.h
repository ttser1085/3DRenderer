#pragma once

#include "CoreEvent.h"

#include <Observer.h>

namespace r3d {

class Broker {
	using Events = std::vector<CoreEvent>;

	using Output = NSLibrary::CObservableData<Events, NSLibrary::CByReference>;
	using Input = NSLibrary::CObserver<Events, NSLibrary::CByReference>;

public:
	void handle(CoreEvent&& event);

	void subscribe(Input* input);

private:
	Events events_;
	Output output_;
};

} // namespace r3d
