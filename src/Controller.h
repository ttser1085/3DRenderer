#pragma once

#include "Linalg/LinalgBase.h"
#include "ModelEvent.h"
#include "CoreEvent.h"
#include "Broker.h"

namespace r3d {

class Controller {
	using EventInput =
		NSLibrary::CColdInput<ModelEvent, NSLibrary::CByReference>;

public:
	explicit Controller(Broker& broker);

	EventInput* eventPort() noexcept;

private:
	class Visitor {
	public:
		explicit Visitor(Broker& broker);

		void operator()(const Tick&);
		void operator()(const KeyPressed&);
		void operator()(const MouseMoved&);

	private:
		Broker& broker_;
	};

	Visitor visitor_;
	EventInput event_in_;
};

} // namespace r3d
