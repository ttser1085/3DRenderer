#pragma once

#include "ModelEvent.h"

#include <Observer.h>
#include <SFML/Graphics.hpp>

namespace r3d {

class RuntimeComponent {

	using WindowPtr = std::shared_ptr<sf::RenderWindow>;
	using screen_size_t = uint32_t; // sf::Uint32 removed from sfml :(
	using EventOutput = ModelEventObservable;

public:
	enum Width : screen_size_t;
	enum Height : screen_size_t;

	RuntimeComponent(Width win_width, Height win_height,
					 const std::string& win_title);

	WindowPtr getWindowPtr() const noexcept;
	void attachEventPort(ModelEventObserver* obs);

	void run();

private:
	WindowPtr window_;
	EventOutput event_out_;
};

} // namespace r3d
