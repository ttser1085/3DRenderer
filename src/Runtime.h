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
	explicit Runtime(const std::string& win_title);

	WindowRawPtr window() const noexcept;
	void attachEventPort(EventInput* obs);

	void run();

private:
	void onEvent(const sf::Event& event);

	WindowPtr window_;
	EventOutput event_out_;

	static constexpr inttypes::Width kDefaultWidth = inttypes::Width{1280};
	static constexpr inttypes::Height kDefaultHeight = inttypes::Height{720};
};

} // namespace r3d
