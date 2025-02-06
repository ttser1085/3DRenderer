#include "Runtime.h"

namespace r3d {

Runtime::Runtime(const std::string& win_title)
	: window_(std::make_unique<sf::RenderWindow>(sf::VideoMode(kDefaultSize),
												 win_title)) {}

Runtime::WindowRawPtr Runtime::window() const noexcept { return window_.get(); }

void Runtime::subscribe(ModelReceiver* receiver) {
	model_sender_.subscribe(receiver);
}

void Runtime::subscribe(ViewReceiver* receiver) {
	view_sender_.subscribe(receiver);
}

void Runtime::run() {
	while (window_->isOpen()) {
		while (std::optional event_opt = window_->pollEvent()) {
			onEvent(std::move(event_opt.value()));
		}

		send(RenderEvent{});
	}
}

void Runtime::onEvent(sf::Event event) {
	if (event.is<sf::Event::Closed>()) {
		window_->close();
		exit(EXIT_SUCCESS);
	} else if (event.is<sf::Event::Resized>()) {
		ViewEvent view_event{std::move(*event.getIf<sf::Event::Resized>())};
		send(view_event);
	}
}

void Runtime::send(const ModelEvent& event) { model_sender_.set(event); }

void Runtime::send(const ViewEvent& event) { view_sender_.set(event); }

} // namespace r3d
