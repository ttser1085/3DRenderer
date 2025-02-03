#include "View.h"

#include "Runtime.h"

#include <SFML/Graphics.hpp>

namespace r3d {

View::View(WindowPtr window)
	: window_(window),
	  frame_in_([this](FrozenFrame frame) { showFrame(std::move(frame)); }) {}

View::FrameInput* View::framePort() noexcept { return &frame_in_; }

void View::showFrame(FrozenFrame frame) {
	if (frame == nullptr) { // model didn't send frame - for example in subscribe notification
		return;
	}

	sf::Texture texture({frame->width(), frame->height()});
	texture.update(frame->data());

	sf::Sprite sprite(texture);
	scaleAndCentrilize(sprite);

	window_->clear();
	window_->draw(sprite);
	window_->display();
}

void View::scaleAndCentrilize(sf::Sprite& sprite) const {
	sf::Vector2u window_size = window_->getSize();
	sf::Vector2u texture_size = sprite.getTexture().getSize();

	float scale_x = static_cast<float>(window_size.x) / texture_size.x;
	float scale_y = static_cast<float>(window_size.y) / texture_size.y;
	float scale = std::min(scale_x, scale_y);

	sprite.setScale({scale, scale});
	sprite.setPosition({(window_size.x - texture_size.x * scale) / 2.0f,
						(window_size.y - texture_size.y * scale) / 2.0f});
}

} // namespace r3d
