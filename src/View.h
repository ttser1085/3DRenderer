#pragma once

#include "Communication.h"
#include "Messages/FrozenFrame.h"

#include <SFML/Graphics.hpp>

namespace r3d {

class View {
	using FrameInput = HotInput<FrozenFrame, ByVal>;
	using ResizeInput = ColdInput<sf::Event::Resized, ByRef>;
	using TextInput = HotStreamInput<sf::Text>;

public:
	explicit View(sf::RenderWindow* window);

	FrameInput* frameInput();
	ResizeInput* resizeInput();
	TextInput* textInput();

private:
	sf::RenderWindow* window() const noexcept;

	void showFrame(FrozenFrame frame);
	void scaleAndCentrilize(sf::Sprite& sprite) const;
	void handleResize(const sf::Event::Resized& event);
	void renderTexts(const std::vector<sf::Text>& texts);

	sf::RenderWindow* window_;

	FrameInput frame_input_;
	ResizeInput resize_input_;
	TextInput text_input_;
};

} // namespace r3d
