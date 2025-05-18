#pragma once

#include "Communication.h"
#include "Messages/Keyboard.h"
#include "Messages/Mouse.h"
#include "Messages/Tick.h"

#include <Observer.h>
#include <SFML/Graphics.hpp>

namespace r3d {

class Runtime {
	using TickOutput = Output<Tick>;
	using MouseOutput = Output<MouseMoved>;
	using KeyOutput = Output<KeyPressed>;
	using ResizeOutput = Output<sf::Event::Resized>;
	using PrintOutput = Output<std::variant<std::string, Tick>>;

public:
	explicit Runtime(const std::string& win_title);

	sf::RenderWindow* window() noexcept;

	void run();

	void subscribe(Input<Tick>*);
	void subscribe(Input<MouseMoved>*);
	void subscribe(Input<KeyPressed>*);
	void subscribe(Input<sf::Event::Resized>*);
	void subscribe(Input<std::variant<std::string, Tick>>*);

private:
	void onEvent(sf::Event event);
	void checkKeysPressed();

	static constexpr sf::Vector2u kDefaultSize = sf::Vector2u{1440, 900};

	sf::RenderWindow window_;

	TickOutput tick_output_;
	MouseOutput mouse_output_;
	KeyOutput key_output_;
	ResizeOutput resize_output_;
	PrintOutput print_output_;
};

} // namespace r3d
