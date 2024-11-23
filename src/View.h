#pragma once

#include "RuntimeComponent.h"
#include "Frame.h"

namespace r3d {

class View {

using WindowPtr = std::shared_ptr<sf::RenderWindow>;

public:
	View(const RuntimeComponent& runtime_comp);

	FrameObserver* getFramePort() noexcept;

private:
	void showFrame(FramePtr frame);

	WindowPtr window_;
	FrameColdInput frame_port_in_;
};

} // namespace r3d
