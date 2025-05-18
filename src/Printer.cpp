#include "Printer.h"

namespace r3d {

Printer::Printer()
	: input_([this](const std::vector<std::string>& strs) { render(strs); }) {}

void Printer::setFont(sf::Font&& font) { font_ = std::move(font); }

ColdStreamInput<std::string>* Printer::input() { return &input_; }

void Printer::subscribe(StreamInput<sf::Text>* input) {
	output_.subscribe(input);
}

void Printer::render(const std::vector<std::string>& strs) {
	sf::Vector2f text_pos{15.0f, 10.0f};
	for (const auto& str : strs) {
		sf::Text text(font_, str);
		text.setPosition(text_pos);
		text.setCharacterSize(30);
		text.setFillColor(sf::Color::White);
		text.setOutlineThickness(1);
		text.setOutlineColor(sf::Color::Red);

		output_.append(std::move(text));
		text_pos.y += 45.0f;
	}

	output_.flush();
}

} // namespace r3d
