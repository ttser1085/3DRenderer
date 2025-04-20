#include "Controller.h"

#include "Broker.h"
#include "Linalg/LinalgBase.h"

namespace r3d {

r3d::Controller::Controller(Broker& broker)
	: visitor_(broker),
	  Base([this](const ModelEvent& event) { std::visit(visitor_, event); }) {}

Controller::Visitor::Visitor(Broker& broker) : broker_(broker) {}

void Controller::Visitor::operator()(const Tick& tick) {
	broker_.handle(Update{tick.dtime.asSeconds()});
}

void Controller::Visitor::operator()(const KeyPressed& pressed) {
	using sf::Keyboard::Key;

	switch (pressed.key) {
	case Key::W: {
		broker_.handle(MoveCamera{-linalg::Vec3::UnitZ()});
		break;
	}

	case Key::A: {
		broker_.handle(MoveCamera{-linalg::Vec3::UnitX()});
		break;
	}

	case Key::S: {
		broker_.handle(MoveCamera{linalg::Vec3::UnitZ()});
		break;
	}

	case Key::D: {
		broker_.handle(MoveCamera{linalg::Vec3::UnitX()});
		break;
	}

	case Key::LShift:
	case Key::RShift: {
		broker_.handle(MoveCamera{linalg::Vec3::UnitY()});
		break;
	}

	case Key::LControl:
	case Key::RControl: {
		broker_.handle(MoveCamera{-linalg::Vec3::UnitY()});
		break;
	}

	default:
		break;
	}
}

void Controller::Visitor::operator()(const MouseMoved& moved) {
	broker_.handle(
		RotateCamera{static_cast<linalg::Float>(moved.delta.x) /
						 static_cast<linalg::Float>(moved.win_size.x),
					 static_cast<linalg::Float>(moved.delta.y) /
						 static_cast<linalg::Float>(moved.win_size.y),
					 0.0});
}

} // namespace r3d
