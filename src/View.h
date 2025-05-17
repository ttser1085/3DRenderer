#pragma once

#include "Communication.h"
#include "Core/Frame.h"

#include <SFML/Graphics.hpp>

namespace r3d {

class View {
	using FrameInput = HotInput<FrozenFrame, ByVal>;
	using ResizeInput = ColdInput<sf::Event::Resized, ByRef>;

public:
	explicit View(sf::RenderWindow* window);

	FrameInput* frameInput();
	ResizeInput* resizeInput();

private:
	sf::RenderWindow* window() const noexcept;

	void showFrame(FrozenFrame frame);
	void scaleAndCentrilize(sf::Sprite& sprite) const;
	void handleResize(const sf::Event::Resized& event);
	void loadFont(const std::string& path);
	void renderText(const std::string& str);

	sf::RenderWindow* window_;
	sf::Font font_;

	FrameInput frame_input_;
	ResizeInput resize_input_;
};

} // namespace r3d
