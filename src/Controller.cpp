#include "Controller.h"

namespace r3d {

r3d::Controller::Controller(ModelRef model)
	: visitor_(model), event_in_([this](const ModelEvent& event) {
		  std::visit(visitor_, event);
	  }) {}

Controller::EventInput* Controller::eventPort() noexcept { return &event_in_; }

Controller::ControllerVisitor::ControllerVisitor(ModelRef model)
	: model_(model) {}

void Controller::ControllerVisitor::operator()(NoneEvent) const {}

void Controller::ControllerVisitor::operator()(RenderEvent) const {
	model_.get().renderFrame();
}

void Controller::ControllerVisitor::operator()(
	const ResizeEvent& resize_event) const {
	model_.get().resizeFrame(resize_event.new_width, resize_event.new_height);
}

} // namespace r3d
