#include "Controller.h"

namespace r3d {

r3d::Controller::Controller(Model& model)
	: model_(model),
	  event_port_in_([this](ModelEvent event) { this->onModelEvent(event); }) {}

NSLibrary::CObserver<ModelEvent>* Controller::getEventPort() {
	return &event_port_in_;
}

void Controller::onModelEvent(ModelEvent evevt) {
	switch (evevt) {
	case ModelEvent::START_RENDER:
		model_.startRender();
		break;

	default:
		break;
	}
}

} // namespace r3d
