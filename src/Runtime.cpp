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
		TickSender::set(Tick{dtime});

		window()->display();
	}
}

void Runtime::onEvent(sf::Event event) {
	if (event.is<sf::Event::Closed>()) {
		window_.close();
		exit(EXIT_SUCCESS);
	} else if (event.is<sf::Event::Resized>()) {
		ViewSender::set(*event.getIf<sf::Event::Resized>());
	} else if (event.is<sf::Event::MouseMovedRaw>()) {
		MouseMoved mouse_event{event.getIf<sf::Event::MouseMovedRaw>()->delta,
							   window_.getSize()};
		MouseSender::set(mouse_event);
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
		KeySender::set(KeyPressed{Key::W});
	}

	if (isKeyPressed(Key::A)) {
		KeySender::set(KeyPressed{Key::A});
	}

	if (isKeyPressed(Key::S)) {
		KeySender::set(KeyPressed{Key::S});
	}

	if (isKeyPressed(Key::D)) {
		KeySender::set(KeyPressed{Key::D});
	}

	if (isKeyPressed(Key::LShift)) {
		KeySender::set(KeyPressed{Key::LShift});
	}

	if (isKeyPressed(Key::RShift)) {
		KeySender::set(KeyPressed{Key::RShift});
	}

	if (isKeyPressed(Key::LControl)) {
		KeySender::set(KeyPressed{Key::LControl});
	}

	if (isKeyPressed(Key::RControl)) {
		KeySender::set(KeyPressed{Key::RControl});
	}
}

} // namespace r3d
