#include "Controller.h"

#include "Broker.h"
#include "Linalg/LinalgBase.h"
#include "Utils/Overloaded.h"

namespace r3d {

r3d::Controller::Controller(Broker& broker)
	: broker_(broker), BaseType([this](const ModelEvent& event) {
		  utils::Visit(
			  event, [this](const Tick& tick) { handleTick(tick); },
			  [this](const KeyPressed& pressed) { handleKeyPressed(pressed); },
			  [this](const MouseMoved& moved) { handleMouseMoved(moved); });
	  }) {}

void Controller::handleTick(const Tick& tick) {
	broker_.handle(Update{tick.dtime.asSeconds()});
}

void Controller::handleKeyPressed(const KeyPressed& pressed) {
	using sf::Keyboard::Key;

	switch (pressed.key) {
	case Key::W: {
		broker_.handle(MoveCamera{-lalg::Vec3::UnitZ()});
		break;
	}

	case Key::A: {
		broker_.handle(MoveCamera{-lalg::Vec3::UnitX()});
		break;
	}

	case Key::S: {
		broker_.handle(MoveCamera{lalg::Vec3::UnitZ()});
		break;
	}

	case Key::D: {
		broker_.handle(MoveCamera{lalg::Vec3::UnitX()});
		break;
	}

	case Key::LShift:
	case Key::RShift: {
		broker_.handle(MoveCamera{lalg::Vec3::UnitY()});
		break;
	}

	case Key::LControl:
	case Key::RControl: {
		broker_.handle(MoveCamera{-lalg::Vec3::UnitY()});
		break;
	}

	default:
		break;
	}
}

void Controller::handleMouseMoved(const MouseMoved& moved) {
	broker_.handle(RotateCamera{static_cast<lalg::Float>(moved.delta.x) /
									static_cast<lalg::Float>(moved.win_size.x),
								static_cast<lalg::Float>(moved.delta.y) /
									static_cast<lalg::Float>(moved.win_size.y),
								0.0});
}

} // namespace r3d
