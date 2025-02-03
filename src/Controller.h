#pragma once

#include "ModelEvent.h"

namespace r3d {

class Model;

class Controller {

	using ModelRef = Model&;

	using EventInput =
		NSLibrary::CColdInput<ModelEvent, NSLibrary::CByReference>;

public:
	explicit Controller(ModelRef model);

	EventInput* eventPort() noexcept;

private:
	class ControllerVisitor {
	public:
		explicit ControllerVisitor(ModelRef model);

		void operator()(NoneEvent) const;
		void operator()(RenderEvent) const;

	private:
		ModelRef model_;
	};

	ControllerVisitor visitor_;
	EventInput event_in_;
};

} // namespace r3d
