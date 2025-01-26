#pragma once

#include "Runtime.h"

namespace r3d {

class View {

	using WindowPtr = sf::RenderWindow*;

	using FrameInput = NSLibrary::CHotInput<FramePtr, NSLibrary::CByValue>;

public:
	View(WindowPtr window);

	FrameInput* framePort() noexcept;

private:
	void showFrame(FramePtr frame);

	void scaleAndCentrilize(sf::Sprite& sprite) const;

	WindowPtr window_;
	FrameInput frame_in_;
};

} // namespace r3d
