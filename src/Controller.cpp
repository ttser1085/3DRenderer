#include "Controller.h"

#include "Model.h"

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

} // namespace r3d
