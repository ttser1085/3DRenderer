#include "View.h"

#include "Runtime.h"

#include <SFML/Graphics.hpp>

namespace r3d {

View::Visitor::Visitor(WindowPtr window) : window_(window) {}

View::WindowPtr View::Visitor::window() const noexcept { return window_; }

void View::Visitor::operator()(const sf::Event::Resized& event) const {
	sf::Vector2u new_size = event.size;
	window_->setSize(new_size);
	sf::FloatRect area({0.0f, 0.0f}, {static_cast<float>(new_size.x),
									  static_cast<float>(new_size.y)});
	window_->setView(sf::View(area));
}

View::View(WindowPtr window)
	: visitor_(window),
	  frame_in_([this](FrozenFrame frame) { showFrame(std::move(frame)); }),
	  event_in_(
		  [this](const ViewEvent& event) { std::visit(visitor_, event); }) {}

View::FrameInput* View::framePort() noexcept { return &frame_in_; }

View::EventInput* View::eventPort() noexcept { return &event_in_; }

View::WindowPtr View::window() const noexcept { return visitor_.window(); }

void View::showFrame(FrozenFrame frame) {
	if (frame == nullptr) {
		// model didn't send frame - for example in
		// subscribe notification
		return;
	}

	sf::Texture texture({frame->width(), frame->height()});
	texture.update(frame->data());

	sf::Sprite sprite(texture);
	scaleAndCentrilize(sprite);

	window()->clear();
	window()->draw(sprite);
	window()->display();
}

void View::scaleAndCentrilize(sf::Sprite& sprite) const {
	sf::Vector2u window_size = window()->getSize();
	sf::Vector2u texture_size = sprite.getTexture().getSize();

	Float scale_x = static_cast<Float>(window_size.x) / texture_size.x;
	Float scale_y = static_cast<Float>(window_size.y) / texture_size.y;
	Float scale = std::min(scale_x, scale_y);

	sprite.setScale({scale, scale});
	sprite.setPosition({(window_size.x - texture_size.x * scale) / 2.0f,
						(window_size.y - texture_size.y * scale) / 2.0f});
}

} // namespace r3d
