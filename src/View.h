#pragma once

#include "Runtime.h"

namespace r3d {

class View {

	using WindowPtr = sf::RenderWindow*;

	using FrameInput = NSLibrary::CColdInput<FramePtr, NSLibrary::CByValue>;

public:
	View(WindowPtr window);

	FrameInput* getFramePort() noexcept;

private:
	void showFrame(FramePtr frame);

	WindowPtr window_;
	FrameInput frame_in_;
};

} // namespace r3d
