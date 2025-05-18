#pragma once

#include <SFML/System/Vector2.hpp>

namespace r3d {

struct MouseMoved {
	sf::Vector2i delta;
	sf::Vector2u win_size;
};

} // namespace r3d
