#pragma once

#include <Observer.h>
#include <SFML/System.hpp>
#include <SFML/Window/Keyboard.hpp>

#include <variant>
#include <vector>

namespace r3d {

struct KeyPressed {
    sf::Keyboard::Key key;
};

struct Tick {
    sf::Time dtime;
};

using ModelEvent = std::variant<Tick, KeyPressed>;

} // namespace r3d
