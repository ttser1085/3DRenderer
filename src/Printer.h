#pragma once

#include "Communication.h"

#include "SFML/Graphics.hpp"

#include <string>

namespace r3d {

class Printer {
public:
    Printer();

    void setFont(sf::Font&&);

    ColdStreamInput<std::string>* input();

    void subscribe(StreamInput<sf::Text>*);

private:
    void render(const std::vector<std::string>&);

    sf::Font font_;

    ColdStreamInput<std::string> input_;
    StreamOutput<sf::Text> output_;
};

} // namespace r3d
