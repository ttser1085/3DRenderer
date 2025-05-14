#pragma once

#include "Communication.h"
#include "Core/Frame.h"

#include <SFML/Graphics.hpp>

namespace r3d {

class View : public HotReceiver<FrozenFrame, ByVal>,
			 public ColdReceiver<sf::Event::Resized, ByRef> {
	using FrameReceiver = HotReceiver<FrozenFrame, ByVal>;
	using EventReceiver = ColdReceiver<sf::Event::Resized, ByRef>;

	using WindowPtr = sf::RenderWindow*;

public:
	explicit View(WindowPtr window);

private:
	WindowPtr window() const noexcept;

	void showFrame(FrozenFrame frame);
	void scaleAndCentrilize(sf::Sprite& sprite) const;
	void handleResize(const sf::Event::Resized& event);
	void loadFont(const std::string& path);
	void renderText(const std::string& str);

	WindowPtr window_;
	sf::Font font_;
};

} // namespace r3d
