#pragma once

#include "Model.h"
#include "ModelEvent.h"

#include <functional>

namespace r3d {
	
class Controller {

	using ModelRef = std::reference_wrapper<Model>;
	using EventInput = ModelEventColdInput;

public:
	Controller(ModelRef model);

	ModelEventObserver* getEventPort() noexcept;

private:
	void onModelEvent(const ModelEvent& evevt);

	ModelRef model_;
	EventInput event_in_;
};

} // namespace r3d
