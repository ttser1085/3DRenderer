#include "Controller.h"

#include "Model.h"

namespace r3d {

r3d::Controller::Controller(ModelRef model)
	: visitor_(model), event_in_([this](const ModelEvent& event) {
		  std::visit(visitor_, event);
	  }) {}

Controller::EventInput* Controller::eventPort() noexcept { return &event_in_; }

Controller::Visitor::Visitor(ModelRef model) : model_(model) {}

void Controller::Visitor::operator()(const Tick& tick) {
	//std::cout << movement_dir_ << "\n\n";

	model_.moveCamera(movement_dir_.normalized(), tick.dtime.asSeconds());
	movement_dir_ = Vec3::Zero();

	model_.renderFrame();
}

void Controller::Visitor::operator()(const KeyPressed& pressed) {
	using sf::Keyboard::Key;

	switch (pressed.key) {
	case Key::W: {
		movement_dir_(2) -= 1.0f;
		break;
	}

	case Key::A: {
		movement_dir_(0) -= 1.0f;
		break;
	}

	case Key::S: {
		movement_dir_(2) += 1.0f;
		break;
	}

	case Key::D: {
		movement_dir_(0) += 1.0f;
		break;
	}

	case Key::LShift:
	case Key::RShift: {
		movement_dir_(1) += 1.0f;
		break;
	}

	case Key::LControl:
	case Key::RControl: {
		movement_dir_(1) -= 1.0f;
		break;
	}

	default:
		break;
	}
}

} // namespace r3d
