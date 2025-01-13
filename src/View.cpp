#include "View.h"

namespace r3d {

View::View(const RuntimeComponent& runtime_comp)
	: window_(runtime_comp.getWindowPtr()),
	  frame_in_([this](FramePtr frame) { showFrame(frame); }) {}

FrameObserver* View::getFramePort() noexcept { return &frame_in_; }

void View::showFrame(FramePtr frame) {
	assert(frame != nullptr);
	assert(frame->getWidth() == window_->getSize().x);
	assert(frame->getHeight() == window_->getSize().y); // resizing should be before rendering

	sf::Texture texture(window_->getSize());
	texture.update(frame->data());

	sf::Sprite sprite(texture);
	window_->draw(sprite);
}

} // namespace r3d
