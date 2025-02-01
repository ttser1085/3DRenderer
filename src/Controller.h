#pragma once

#include "Model.h"
#include "ModelEvent.h"

#include <functional>

namespace r3d {

class Controller {

	using ModelRef = std::reference_wrapper<Model>;

	using EventInput = NSLibrary::CColdInput<ModelEvent, NSLibrary::CByReference>;

public:
	explicit Controller(ModelRef model);

	EventInput* eventPort() noexcept;

private:
	class ControllerVisitor {
	public:
		explicit ControllerVisitor(ModelRef model);

		void operator()(NoneEvent) const;
		void operator()(RenderEvent) const;
		void operator()(const ResizeEvent&) const;

	private:
		ModelRef model_;
	};

	ControllerVisitor visitor_;
	EventInput event_in_;
};

} // namespace r3d
