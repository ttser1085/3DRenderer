#include "Runtime.h"

#include <iostream>

namespace r3d {

Runtime::Runtime(const std::string& win_title)
	: window_(sf::VideoMode(kDefaultSize), win_title) {
	window_.setMouseCursorVisible(false);
	sf::Mouse::setPosition(sf::Vector2i{kDefaultSize.x / 2, kDefaultSize.y / 2},
						   window_);
}

sf::RenderWindow* Runtime::window() noexcept { return &window_; }

void Runtime::run() {
	sf::Clock clock;
	while (window_.isOpen()) {
		while (std::optional event_opt = window_.pollEvent()) {
			onEvent(std::move(event_opt.value()));
		}

		checkKeysPressed();

		sf::Time dtime = clock.restart();
		tick_output_.set(Tick{dtime});

		int fps = static_cast<int>(1.0f / dtime.asSeconds());
		print_output_.set("FPS: " + std::to_string(fps));
		print_output_.set(Tick{dtime});

		window()->display();
	}
}

void Runtime::onEvent(sf::Event event) {
	if (event.is<sf::Event::Closed>()) {
		window_.close();
		exit(EXIT_SUCCESS);
	} else if (event.is<sf::Event::Resized>()) {
		resize_output_.set(*event.getIf<sf::Event::Resized>());
	} else if (event.is<sf::Event::MouseMovedRaw>()) {
		MouseMoved mouse_event{event.getIf<sf::Event::MouseMovedRaw>()->delta,
							   window_.getSize()};
		mouse_output_.set(mouse_event);
		sf::Mouse::setPosition(
			sf::Vector2i{kDefaultSize.x / 2, kDefaultSize.y / 2}, window_);
	}
}

void Runtime::checkKeysPressed() {
	using sf::Keyboard::isKeyPressed, sf::Keyboard::Key;

	if (isKeyPressed(Key::Escape)) {
		window_.close();
		exit(EXIT_SUCCESS);
	}

	if (isKeyPressed(Key::W)) {
		key_output_.set(KeyPressed{Key::W});
	}

	if (isKeyPressed(Key::A)) {
		key_output_.set(KeyPressed{Key::A});
	}

	if (isKeyPressed(Key::S)) {
		key_output_.set(KeyPressed{Key::S});
	}

	if (isKeyPressed(Key::D)) {
		key_output_.set(KeyPressed{Key::D});
	}

	if (isKeyPressed(Key::LShift)) {
		key_output_.set(KeyPressed{Key::LShift});
	}

	if (isKeyPressed(Key::RShift)) {
		key_output_.set(KeyPressed{Key::RShift});
	}

	if (isKeyPressed(Key::LControl)) {
		key_output_.set(KeyPressed{Key::LControl});
	}

	if (isKeyPressed(Key::RControl)) {
		key_output_.set(KeyPressed{Key::RControl});
	}
}

void Runtime::subscribe(Input<Tick>* input) {
	tick_output_.subscribe(input);
}

void Runtime::subscribe(Input<MouseMoved>* input) {
	mouse_output_.subscribe(input);
}

void Runtime::subscribe(Input<KeyPressed>* input) {
	key_output_.subscribe(input);
}

void Runtime::subscribe(Input<sf::Event::Resized>* input) {
	resize_output_.subscribe(input);
}

void Runtime::subscribe(Input<std::variant<std::string, Tick>>* input) {
	print_output_.subscribe(input);
}

} // namespace r3d
