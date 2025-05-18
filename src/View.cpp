#include "View.h"

namespace r3d {

View::View(sf::RenderWindow* window)
	: window_(window),
	  frame_input_([this](FrozenFrame frame) { showFrame(std::move(frame)); }),
	  resize_input_(
		  [this](const sf::Event::Resized& resized) { handleResize(resized); }),
	  text_input_(
		  [this](const std::vector<sf::Text>& texts) { renderTexts(texts); }) {}

sf::RenderWindow* View::window() const noexcept { return window_; }

void View::showFrame(FrozenFrame frame) {
	if (!frame.hasData()) {
		// model didn't send frame - for example in
		// subscribe notification
		return;
	}

	sf::Texture texture({static_cast<uint32_t>(frame->width()),
						 static_cast<uint32_t>(frame->height())});
	texture.update(frame->data());

	sf::Sprite sprite(texture);
	scaleAndCentrilize(sprite);

	window()->clear();
	window()->draw(sprite);
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

void View::handleResize(const sf::Event::Resized& resized) {
	sf::Vector2u new_size = resized.size;
	window_->setSize(new_size);
	sf::FloatRect area({0.0f, 0.0f}, {static_cast<float>(new_size.x),
									  static_cast<float>(new_size.y)});
	window_->setView(sf::View(area));
}

void View::renderTexts(const std::vector<sf::Text>& texts) {
	for (const auto& text : texts) {
		window_->draw(text);
	}
}

View::FrameInput* View::frameInput() { return &frame_input_; }

View::ResizeInput* View::resizeInput() { return &resize_input_; }

View::TextInput* View::textInput() { return &text_input_; }

} // namespace r3d
