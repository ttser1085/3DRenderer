#include "Runtime.h"

#include <iostream>

namespace r3d {

Runtime::Runtime(const std::string& win_title)
	: window_(std::make_unique<sf::RenderWindow>(sf::VideoMode(kDefaultSize),
												 win_title)) {
	window_->setMouseCursorVisible(false);
	sf::Mouse::setPosition(sf::Vector2i{kDefaultSize.x / 2, kDefaultSize.y / 2},
						   *window_);
}

Runtime::WindowRawPtr Runtime::window() const noexcept { return window_.get(); }

void Runtime::run() {
	sf::Clock clock;
	while (window_->isOpen()) {
		while (std::optional event_opt = window_->pollEvent()) {
			onEvent(std::move(event_opt.value()));
		}

		checkKeysPressed();

		send(Tick{clock.restart()});
	}
}

void Runtime::onEvent(sf::Event event) {
	if (event.is<sf::Event::Closed>()) {
		window_->close();
		exit(EXIT_SUCCESS);
	} else if (event.is<sf::Event::Resized>()) {
		ViewEvent view_event{std::move(*event.getIf<sf::Event::Resized>())};
		send(view_event);
	} else if (event.is<sf::Event::MouseMovedRaw>()) {
		MouseMoved mouse_event{event.getIf<sf::Event::MouseMovedRaw>()->delta,
							   window_->getSize()};
		send(mouse_event);
		sf::Mouse::setPosition(
			sf::Vector2i{kDefaultSize.x / 2, kDefaultSize.y / 2}, *window_);
	}
}

void Runtime::checkKeysPressed() {
	using sf::Keyboard::isKeyPressed, sf::Keyboard::Key;

	if (isKeyPressed(Key::Escape)) {
		window_->close();
		exit(EXIT_SUCCESS);
	}

	if (isKeyPressed(Key::W)) {
		send(KeyPressed{Key::W});
	}

	if (isKeyPressed(Key::A)) {
		send(KeyPressed{Key::A});
	}

	if (isKeyPressed(Key::S)) {
		send(KeyPressed{Key::S});
	}

	if (isKeyPressed(Key::D)) {
		send(KeyPressed{Key::D});
	}

	if (isKeyPressed(Key::LShift)) {
		send(KeyPressed{Key::LShift});
	}

	if (isKeyPressed(Key::RShift)) {
		send(KeyPressed{Key::RShift});
	}

	if (isKeyPressed(Key::LControl)) {
		send(KeyPressed{Key::LControl});
	}

	if (isKeyPressed(Key::RControl)) {
		send(KeyPressed{Key::RControl});
	}
}

} // namespace r3d
