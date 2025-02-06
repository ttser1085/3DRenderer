#pragma once

#include "ModelEvent.h"
#include "ViewEvent.h"

#include <Observer.h>
#include <SFML/Graphics.hpp>

namespace r3d {

class Runtime {

	using WindowPtr = std::unique_ptr<sf::RenderWindow>;
	using WindowRawPtr = sf::RenderWindow*;

	template<typename Event>
	using EventSender =
		NSLibrary::CObservableData<Event, NSLibrary::CByReference>;

	template<typename Event>
	using EventReceiver = NSLibrary::CObserver<Event, NSLibrary::CByReference>;

	using ModelSender = EventSender<ModelEvent>;
	using ModelReceiver = EventReceiver<ModelEvent>;

	using ViewSender = EventSender<ViewEvent>;
	using ViewReceiver = EventReceiver<ViewEvent>;

public:
	explicit Runtime(const std::string& win_title);

	WindowRawPtr window() const noexcept;

	void subscribe(ModelReceiver* receiver);
	void subscribe(ViewReceiver* receiver);

	void run();

private:
	void onEvent(sf::Event event);

	void send(const ModelEvent& event);
	void send(const ViewEvent& event);

	WindowPtr window_;

	ModelSender model_sender_;
	ViewSender view_sender_;

	static constexpr sf::Vector2u kDefaultSize = sf::Vector2u{1280, 720};
};

} // namespace r3d
