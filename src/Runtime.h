#pragma once

#include "Input.h"

#include <Observer.h>
#include <SFML/Graphics.hpp>

namespace r3d {

class Runtime : public Input {
	using WindowPtr = std::unique_ptr<sf::RenderWindow>;
	using WindowRawPtr = sf::RenderWindow*;

public:
	explicit Runtime(const std::string& win_title);

	WindowRawPtr window() const noexcept;

	void run();

private:
	void onEvent(sf::Event event);
	void checkKeysPressed();

	WindowPtr window_;

	static constexpr sf::Vector2u kDefaultSize = sf::Vector2u{1440, 900};
};

} // namespace r3d
