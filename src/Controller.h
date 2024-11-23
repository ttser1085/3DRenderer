#pragma once

#include "Model.h"
#include "ModelEvent.h"

namespace r3d {
	
class Controller {
public:
	Controller(ModelRef model);

	ModelEventObserver* getEventPort() noexcept;

private:
	void onModelEvent(const ModelEvent& evevt);

	ModelRef model_;
	ModelEventColdInput event_port_in_;
};

} // namespace r3d
