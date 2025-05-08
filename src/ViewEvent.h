#pragma once

#include <SFML/Window/Event.hpp>

#include <variant>

namespace r3d {

struct LoadFont {
    std::string path;
};

struct RenderText {
    std::string text;
};

using ViewEvent = std::variant<sf::Event::Resized, RenderText, LoadFont>;

} // namespace r3d
