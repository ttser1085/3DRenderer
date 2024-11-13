#include "View.h"

namespace r3d {

View::View(uint32_t win_width, uint32_t win_height,
		   const std::string& win_title) noexcept
	: window_(sf::VideoMode({win_width, win_height}), win_title, sf::Style::Titlebar | sf::Style::Close),
	  frame_port_in_([this](uint8_t* data) { this->renderFrame(data); }),
	  event_port_out_([this]() { return this->current_event_; }) {}

NSLibrary::CObserver<uint8_t*>* View::getFramePort() { return &frame_port_in_; }

void View::attachEventPort(NSLibrary::CObserver<ModelEvent>* obs) {
	event_port_out_.subscribe(obs);
}

void View::renderFrame(uint8_t* data) {
	sf::Texture texture(window_.getSize());
	texture.update(data);

	sf::Sprite sprite(texture);
	window_.draw(sprite);
}

void View::run() {
	while (window_.isOpen()) {
		while (const std::optional event = window_.pollEvent()) {
			if (event->is<sf::Event::Closed>())
				window_.close();
		}

		window_.clear();

		// render frame: view -> controller -> model.render()
		current_event_= ModelEvent::START_RENDER;
		event_port_out_.notify();

		window_.display();
	}
}

} // namespace r3d
