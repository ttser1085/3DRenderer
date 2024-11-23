#include "Frame.h"

namespace r3d {

Frame::Frame(Width width, Height height)
	: width_(width), height_(height), storage_(width_ * height_) {}

void Frame::setColor(const Vec2s& pos, Color3 color) {
	storage_[pos(1) * width_ + pos(0)] = Color4::fromColor3(color);
}

Color3 Frame::getColor(const Vec2s& pos) const {
	return Color3::fromColor4(storage_[pos(1) * width_ + pos(0)]);
}

Frame::Width Frame::getWidth() const noexcept { return width_; }

Frame::Height Frame::getHeight() const noexcept { return height_; }

void Frame::changeSize(const Vec2s& new_size) {
	width_ = Width{new_size(0)};
	height_ = Height{new_size(1)};
	storage_.resize(width_ * height_); // it's ok if the picture is damaged
}

void Frame::clear(Color3 color) {
	for (auto& c : storage_) {
		c = Color4::fromColor3(color);
	}
}

uint8_t* Frame::data() {
	if (storage_.empty()) {
		return nullptr;
	}

	return reinterpret_cast<uint8_t*>(storage_.data());
}

} // namespace r3d
