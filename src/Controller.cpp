#include "Controller.h"

#include "Model.h"

namespace r3d {

r3d::Controller::Controller(Model& model)
	: visitor_(model), event_in_([this](const ModelEvent& event) {
		  std::visit(visitor_, event);
	  }) {}

Controller::EventInput* Controller::eventPort() noexcept { return &event_in_; }

Controller::Visitor::Visitor(Model& model) : model_(model) {}

void Controller::Visitor::operator()(const Tick& tick) {
	current_batch_.emplace_back(Update{tick.dtime.asSeconds()});

	std::vector<CoreEvent> temp;
	current_batch_.swap(temp);
	model_.Handle(std::move(temp));
}

void Controller::Visitor::operator()(const KeyPressed& pressed) {
	using sf::Keyboard::Key;

	switch (pressed.key) {
	case Key::W: {
		current_batch_.emplace_back(MoveCamera{-Vec3::UnitZ()});
		break;
	}

	case Key::A: {
		current_batch_.emplace_back(MoveCamera{-Vec3::UnitX()});
		break;
	}

	case Key::S: {
		current_batch_.emplace_back(MoveCamera{Vec3::UnitZ()});
		break;
	}

	case Key::D: {
		current_batch_.emplace_back(MoveCamera{Vec3::UnitX()});
		break;
	}

	case Key::LShift:
	case Key::RShift: {
		current_batch_.emplace_back(MoveCamera{Vec3::UnitY()});
		break;
	}

	case Key::LControl:
	case Key::RControl: {
		current_batch_.emplace_back(MoveCamera{-Vec3::UnitY()});
		break;
	}

	default:
		break;
	}
}

void Controller::Visitor::operator()(const MouseMoved& moved) {
	current_batch_.emplace_back(
		RotateCamera{static_cast<Float>(moved.delta.x) /
						 static_cast<Float>(moved.win_size.x),
					 static_cast<Float>(moved.delta.y) /
						 static_cast<Float>(moved.win_size.y),
					 0.0});
}

} // namespace r3d
