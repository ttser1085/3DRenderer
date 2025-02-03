#pragma once

#include "Frame.h"

namespace sf {

class RenderWindow;

class Sprite;

} // namespace sf

namespace r3d {

class View {

	using WindowPtr = sf::RenderWindow*;

	using FrameInput = NSLibrary::CHotInput<FrozenFrame, NSLibrary::CByValue>;

public:
	explicit View(WindowPtr window);

	FrameInput* framePort() noexcept;

private:
	void showFrame(FrozenFrame frame);

	void scaleAndCentrilize(sf::Sprite& sprite) const;

	WindowPtr window_;
	FrameInput frame_in_;
};

} // namespace r3d
