#pragma once

#include "ModelEvent.h"

#include <Observer.h>
#include <SFML/Graphics.hpp>

namespace r3d {

class Runtime {

	using WindowPtr = std::unique_ptr<sf::RenderWindow>;
	using WindowRawPtr = sf::RenderWindow*;

	using EventOutput =
		NSLibrary::CObservableData<ModelEvent, NSLibrary::CByReference>;
	using EventInput =
		NSLibrary::CObserver<ModelEvent, NSLibrary::CByReference>;

public:
	Runtime(Width win_width, Height win_height,
					 const std::string& win_title);

	WindowRawPtr getWindowPtr() const noexcept;
	void attachEventPort(EventInput* obs);

	void run();

private:
	void onEvent(const sf::Event& event);

	WindowPtr window_;
	EventOutput event_out_;
};

} // namespace r3d
