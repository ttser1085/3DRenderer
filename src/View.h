#pragma once

#include "Frame.h"
#include "ViewEvent.h"

namespace sf {

class RenderWindow;

class Sprite;

} // namespace sf

namespace r3d {

class View {

	using WindowPtr = sf::RenderWindow*;

	using FrameInput = NSLibrary::CHotInput<FrozenFrame, NSLibrary::CByValue>;
	using EventInput =
		NSLibrary::CColdInput<ViewEvent, NSLibrary::CByReference>;

public:
	explicit View(WindowPtr window);

	FrameInput* framePort() noexcept;
	EventInput* eventPort() noexcept;

private:
	WindowPtr window() const noexcept;

	void showFrame(FrozenFrame frame);
	void scaleAndCentrilize(sf::Sprite& sprite) const;

	class Visitor {
	public:
		explicit Visitor(WindowPtr window_);

		WindowPtr window() const noexcept;

		void operator()(const sf::Event::Resized&) const;

	private:
		WindowPtr window_;
	};

	Visitor visitor_;

	FrameInput frame_in_;
	EventInput event_in_;
};

} // namespace r3d
