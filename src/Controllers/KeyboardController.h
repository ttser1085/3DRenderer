#pragma once

#include "Communication.h"
#include "Messages/Core.h"
#include "Messages/Keyboard.h"

namespace r3d {

class KeyboardController {
public:
	KeyboardController()
		: input_([this](const KeyPressed& pressed) {
			  using sf::Keyboard::Key;

			  switch (pressed.key) {
			  case Key::W: {
				  output_.set(MoveCamera{-lalg::Vec3::UnitZ()});
				  break;
			  }

			  case Key::A: {
				  output_.set(MoveCamera{-lalg::Vec3::UnitX()});
				  break;
			  }

			  case Key::S: {
				  output_.set(MoveCamera{lalg::Vec3::UnitZ()});
				  break;
			  }

			  case Key::D: {
				  output_.set(MoveCamera{lalg::Vec3::UnitX()});
				  break;
			  }

			  case Key::LShift:
			  case Key::RShift: {
				  output_.set(MoveCamera{lalg::Vec3::UnitY()});
				  break;
			  }

			  case Key::LControl:
			  case Key::RControl: {
				  output_.set(MoveCamera{-lalg::Vec3::UnitY()});
				  break;
			  }

			  default:
				  break;
			  }
		  }) {}

	ColdInput<KeyPressed>* input() { return &input_; }

	void subscribe(Input<MoveCamera>* input) { output_.subscribe(input); }

private:
	ColdInput<KeyPressed> input_;
	Output<MoveCamera> output_;
};

} // namespace r3d
