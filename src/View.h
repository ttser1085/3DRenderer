#pragma once

#include "Communication.h"
#include "Core/Frame.h"
#include "ViewEvent.h"

namespace sf {

class RenderWindow;

class Sprite;

} // namespace sf

namespace r3d {

class View : public HotReceiver<FrozenFrame, NSLibrary::CByValue>,
			 public ColdReceiver<ViewEvent, NSLibrary::CByReference> {
	using FrameReceiver = HotReceiver<FrozenFrame, NSLibrary::CByValue>;
	using EventReceiver = ColdReceiver<ViewEvent, NSLibrary::CByReference>;

	using WindowPtr = sf::RenderWindow*;

public:
	explicit View(WindowPtr window);

private:
	WindowPtr window() const noexcept;

	void showFrame(FrozenFrame frame);
	void scaleAndCentrilize(sf::Sprite& sprite) const;
	void handleResize(const sf::Event::Resized& event);

	WindowPtr window_;
};

} // namespace r3d
