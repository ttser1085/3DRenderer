#pragma once

#include "Communication.h"
#include "ModelEvent.h"
#include "ViewEvent.h"

#include <Observer.h>
#include <SFML/Graphics.hpp>

namespace r3d {

class Runtime : public Sender<KeyPressed, ByRef>,
				public Sender<MouseMoved, ByRef>,
				public Sender<Tick, ByRef>,
				public Sender<ViewEvent, ByRef> {
public:
	using TickSender = Sender<Tick, ByRef>;
	using MouseSender = Sender<MouseMoved, ByRef>;
	using KeySender = Sender<KeyPressed, ByRef>;
	using ViewSender = Sender<ViewEvent, ByRef>;

	explicit Runtime(const std::string& win_title);

	sf::RenderWindow* window() noexcept;

	void run();

private:
	void onEvent(sf::Event event);
	void checkKeysPressed();

	void send(const ViewEvent& event);

	sf::RenderWindow window_;

	static constexpr sf::Vector2u kDefaultSize = sf::Vector2u{1440, 900};
};

} // namespace r3d
