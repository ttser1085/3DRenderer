#pragma once

#include "Communication.h"
#include "ModelEvent.h"
#include "ViewEvent.h"

#include <Observer.h>
#include <SFML/Graphics.hpp>

namespace r3d {

class Runtime : public Sender<ModelEvent, NSLibrary::CByReference>,
				public Sender<ViewEvent, NSLibrary::CByReference> {
	using WindowPtr = std::unique_ptr<sf::RenderWindow>;
	using WindowRawPtr = sf::RenderWindow*;

public:
	using ModelSender = Sender<ModelEvent, NSLibrary::CByReference>;
	using ViewSender = Sender<ViewEvent, NSLibrary::CByReference>;

	explicit Runtime(const std::string& win_title);

	WindowRawPtr window() const noexcept;

	void run();

private:
	void onEvent(sf::Event event);
	void checkKeysPressed();

	void send(const ModelEvent& event);
	void send(const ViewEvent& event);

	WindowPtr window_;

	static constexpr sf::Vector2u kDefaultSize = sf::Vector2u{1440, 900};
};

} // namespace r3d
