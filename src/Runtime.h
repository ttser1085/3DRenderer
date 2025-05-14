#pragma once

#include "Communication.h"
#include "ModelEvent.h"
#include "ViewEvent.h"

#include <Observer.h>
#include <SFML/Graphics.hpp>

namespace r3d {

class Runtime : public Sender<ModelEvent, ByRef>,
				public Sender<ViewEvent, ByRef> {
public:
	using ModelSender = Sender<ModelEvent, ByRef>;
	using ViewSender = Sender<ViewEvent, ByRef>;

	explicit Runtime(const std::string& win_title);

	sf::RenderWindow* window() noexcept;

	void run();

private:
	void onEvent(sf::Event event);
	void checkKeysPressed();

	void send(const ModelEvent& event);
	void send(const ViewEvent& event);

	sf::RenderWindow window_;

	static constexpr sf::Vector2u kDefaultSize = sf::Vector2u{1440, 900};
};

} // namespace r3d
