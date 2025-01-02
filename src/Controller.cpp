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
		auto resize_event = event.getIf<ModelEvent::ResizeFrame>();
		model_.get().resizeFrame(resize_event->new_width, resize_event->new_height);
	} else {
		assert(0);
	}
}

} // namespace r3d
