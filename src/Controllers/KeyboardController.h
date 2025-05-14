#pragma once

#include "Communication.h"
#include "CoreEvent.h"
#include "ModelEvent.h"

namespace r3d {

class KeyboardController : public ColdReceiver<KeyPressed, ByRef>,
						   public Sender<MoveCamera, ByRef> {
public:
	using Receiver = ColdReceiver<KeyPressed, ByRef>;

	KeyboardController()
		: Receiver([this](const KeyPressed& pressed) {
			  using sf::Keyboard::Key;

			  switch (pressed.key) {
			  case Key::W: {
				  set(MoveCamera{-lalg::Vec3::UnitZ()});
				  break;
			  }

			  case Key::A: {
				  set(MoveCamera{-lalg::Vec3::UnitX()});
				  break;
			  }

			  case Key::S: {
				  set(MoveCamera{lalg::Vec3::UnitZ()});
				  break;
			  }

			  case Key::D: {
				  set(MoveCamera{lalg::Vec3::UnitX()});
				  break;
			  }

			  case Key::LShift:
			  case Key::RShift: {
				  set(MoveCamera{lalg::Vec3::UnitY()});
				  break;
			  }

			  case Key::LControl:
			  case Key::RControl: {
				  set(MoveCamera{-lalg::Vec3::UnitY()});
				  break;
			  }

			  default:
				  break;
			  }
		  }) {}
};

} // namespace r3d
