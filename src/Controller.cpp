#include "Controller.h"

namespace r3d {

r3d::Controller::Controller(ModelRef model)
	: model_(model),
	  event_port_in_([this](const ModelEvent& event) { onModelEvent(event); }) {}

ModelEventObserver* Controller::getEventPort() noexcept {
	return &event_port_in_;
}

void Controller::onModelEvent(const ModelEvent& event) {
	if (event.is<ModelEvent::RenderFrame>()) {
		model_.get().renderFrame();
	} else if (event.is<ModelEvent::ResizeFrame>()) {
		model_.get().resizeFrame(event.getIf<ModelEvent::ResizeFrame>()->new_size);
	} else {
		assert(0);
	}
}

} // namespace r3d
