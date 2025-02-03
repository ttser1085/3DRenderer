#include "Runtime.h"

namespace r3d {

Runtime::Runtime(const std::string& win_title)
	: window_(std::make_unique<sf::RenderWindow>(sf::VideoMode(kDefaultSize),
												 win_title)) {}

Runtime::WindowRawPtr Runtime::window() const noexcept { return window_.get(); }

void Runtime::attachEventPort(EventInput* obs) { event_out_.subscribe(obs); }

void Runtime::run() {
	while (window_->isOpen()) {
		while (const std::optional event_opt = window_->pollEvent()) {
			onEvent(event_opt.value());
		}

		event_out_.set(RenderEvent{});
	}
}

void Runtime::onEvent(const sf::Event& event) {
	if (event.is<sf::Event::Closed>()) {
		window_->close();
		exit(EXIT_SUCCESS);
	} else if (event.is<sf::Event::Resized>()) {
		sf::Vector2u new_size = event.getIf<sf::Event::Resized>()->size;
		window_->setSize(new_size);
		sf::FloatRect area({0.0f, 0.0f}, {static_cast<float>(new_size.x),
										  static_cast<float>(new_size.y)});
		window_->setView(sf::View(area));
	}
}

} // namespace r3d
