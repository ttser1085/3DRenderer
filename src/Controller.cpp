#include "Controller.h"

#include "Model.h"

namespace r3d {

r3d::Controller::Controller(ModelRef model)
	: visitor_(model), event_in_([this](const ModelEvent& event) {
		  std::visit(visitor_, event);
	  }) {}

Controller::EventInput* Controller::eventPort() noexcept { return &event_in_; }

Controller::Visitor::Visitor(ModelRef model)
	: model_(model) {}

void Controller::Visitor::operator()(NoneEvent) const {}

void Controller::Visitor::operator()(RenderEvent) const {
	model_.renderFrame();
}

} // namespace r3d
