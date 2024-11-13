#pragma once

#include "Model.h"

#include <Observer.h>

namespace r3d {

enum ModelEvent { START_RENDER };

class Controller {
public:
	Controller(Model& model);

	NSLibrary::CObserver<ModelEvent>* getEventPort();

private:
	void onModelEvent(ModelEvent evevt);

	Model& model_;
	NSLibrary::CColdInput<ModelEvent> event_port_in_;
};

} // namespace r3d
