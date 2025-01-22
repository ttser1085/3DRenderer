#include "RuntimeComponent.h"

namespace r3d {

RuntimeComponent::RuntimeComponent(Width win_width, Height win_height,
								   const std::string& win_title)
	: window_(std::make_shared<sf::RenderWindow>(
		  sf::VideoMode({win_width, win_height}), win_title)) {}

RuntimeComponent::WindowPtr RuntimeComponent::getWindowPtr() const noexcept {
	return window_;
}

void RuntimeComponent::attachEventPort(EventInput* obs) {
	event_out_.subscribe(obs);
}

void RuntimeComponent::run() {
	while (window_->isOpen()) {
		while (const std::optional event_opt = window_->pollEvent()) {
			onEvent(event_opt.value());
		}

		event_out_.set(RenderEvent{});
	}
}

void RuntimeComponent::onEvent(const sf::Event& event) {
	if (event.is<sf::Event::Closed>()) {
		window_->close();
		exit(EXIT_SUCCESS);
	} else if (event.is<sf::Event::Resized>()) {
		sf::Vector2u new_size = event.getIf<sf::Event::Resized>()->size;

		sf::FloatRect area({0.0f, 0.0f}, {static_cast<float>(new_size.x),
										  static_cast<float>(new_size.y)});
		window_->setView(sf::View(area)); // <--- sfml cringe

		event_out_.set(ResizeEvent{static_cast<Width>(new_size.x),
								   static_cast<Height>(new_size.y)});
	}
}

} // namespace r3d
