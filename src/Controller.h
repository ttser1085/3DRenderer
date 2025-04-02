#pragma once

#include "Linalg/LinalgBase.h"
#include "ModelEvent.h"
#include "CoreEvent.h"

namespace r3d {

class Model;

class Controller {
	using EventInput =
		NSLibrary::CColdInput<ModelEvent, NSLibrary::CByReference>;

public:
	explicit Controller(Model& model);

	EventInput* eventPort() noexcept;

private:
	class Visitor {
	public:
		explicit Visitor(Model& model);

		void operator()(const Tick&);
		void operator()(const KeyPressed&);

	private:
		Model& model_;
		std::vector<CoreEvent> current_batch_;
	};

	Visitor visitor_;
	EventInput event_in_;
};

} // namespace r3d
