#pragma once

#include <SFML/Window/Event.hpp>

#include <variant>

namespace r3d {

using ViewEvent = std::variant<sf::Event::Resized>;

} // namespace r3d
