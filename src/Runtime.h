#pragma once

#include "Communication.h"
#include "ModelEvent.h"
#include <Observer.h>
#include <SFML/Graphics.hpp>

namespace r3d {

class Runtime {
	using TickOutput = Output<Tick, ByRef>;
	using MouseOutput = Output<MouseMoved, ByRef>;
	using KeyOutput = Output<KeyPressed, ByRef>;
	using ResizeOutput = Output<sf::Event::Resized, ByRef>;

public:
	explicit Runtime(const std::string& win_title);

	sf::RenderWindow* window() noexcept;

	void run();

	void subscribe(Input<Tick, ByRef>*);
	void subscribe(Input<MouseMoved, ByRef>*);
	void subscribe(Input<KeyPressed, ByRef>*);
	void subscribe(Input<sf::Event::Resized, ByRef>*);

private:
	void onEvent(sf::Event event);
	void checkKeysPressed();

	static constexpr sf::Vector2u kDefaultSize = sf::Vector2u{1440, 900};

	sf::RenderWindow window_;

	TickOutput tick_output_;
	MouseOutput mouse_output_;
	KeyOutput key_output_;
	ResizeOutput resize_output_;
};

} // namespace r3d
