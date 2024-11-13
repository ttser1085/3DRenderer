#pragma once

#include "Controller.h"

#include <Observer.h>
#include <SFML/Graphics.hpp>

namespace r3d {

class View {
public:
	View(uint32_t win_width, uint32_t win_height,
		 const std::string& win_title) noexcept;

	NSLibrary::CObserver<uint8_t*>* getFramePort();
	void attachEventPort(NSLibrary::CObserver<ModelEvent>* obs);

	void run();

private:
	void renderFrame(uint8_t* data);

	sf::RenderWindow window_;

	ModelEvent current_event_;
	NSLibrary::CColdInput<uint8_t*> frame_port_in_;
	NSLibrary::CObservable<ModelEvent> event_port_out_;
};

} // namespace r3d
