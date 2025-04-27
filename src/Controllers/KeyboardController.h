#pragma once

#include "Broker.h"
#include "ModelEvent.h"

namespace r3d {

auto KeyboardController = [](Broker& broker, const KeyPressed& pressed) {
	using sf::Keyboard::Key;

	switch (pressed.key) {
	case Key::W: {
		broker.handle(MoveCamera{-lalg::Vec3::UnitZ()});
		break;
	}

	case Key::A: {
		broker.handle(MoveCamera{-lalg::Vec3::UnitX()});
		break;
	}

	case Key::S: {
		broker.handle(MoveCamera{lalg::Vec3::UnitZ()});
		break;
	}

	case Key::D: {
		broker.handle(MoveCamera{lalg::Vec3::UnitX()});
		break;
	}

	case Key::LShift:
	case Key::RShift: {
		broker.handle(MoveCamera{lalg::Vec3::UnitY()});
		break;
	}

	case Key::LControl:
	case Key::RControl: {
		broker.handle(MoveCamera{-lalg::Vec3::UnitY()});
		break;
	}

	default:
		break;
	}
};

} // namespace r3d
