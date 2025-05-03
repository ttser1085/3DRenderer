#pragma once

#include "Core/Vertex.h"

#include <Observer.h>
#include <SFML/System.hpp>
#include <SFML/Window/Keyboard.hpp>

#include <variant>
#include <vector>

namespace r3d {

struct KeyPressed {
	sf::Keyboard::Key key;
};

struct MouseMoved {
	sf::Vector2i delta;
	sf::Vector2u win_size;
};

struct ParseBegin {
	Vec3 pos;
	Vec3 rotation;
};

struct ParseEnd {};

struct ParseVertex {
	Vertex vertex;
};

struct ParseMesh {
	Index vertices[3];
};

struct Tick {
	sf::Time dtime;
};

using ModelEvent = std::variant<Tick, KeyPressed, MouseMoved, ParseBegin,
								ParseEnd, ParseVertex, ParseMesh>;

} // namespace r3d
