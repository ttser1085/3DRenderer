#pragma once

#include "RuntimeComponent.h"

namespace r3d {

class View {

	using WindowPtr = std::shared_ptr<sf::RenderWindow>;

	using FrameInput = NSLibrary::CColdInput<FramePtr, NSLibrary::CByValue>;

public:
	View(const RuntimeComponent& runtime_comp);

	FrameInput* getFramePort() noexcept;

private:
	void showFrame(FramePtr frame);

	WindowPtr window_;
	FrameInput frame_in_;
};

} // namespace r3d
