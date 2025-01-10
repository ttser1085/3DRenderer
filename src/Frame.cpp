#include "Frame.h"

namespace r3d {

Frame::Frame(Width width, Height height)
	: width_(width), height_(height), storage_(width_ * height_) {}

void Frame::setColor(const Vec2s& pos, Color3b color) {
	storage_[pos(1) * width_ + pos(0)] = Color4b::fromColor3b(color);
}

Color3b Frame::getColor(const Vec2s& pos) const {
	return Color3b::fromColor4b(storage_[pos(1) * width_ + pos(0)]);
}

Frame::Width Frame::getWidth() const noexcept { return width_; }

Frame::Height Frame::getHeight() const noexcept { return height_; }

void Frame::clear(Color3b color) {
	for (auto& c : storage_) {
		c = Color4b::fromColor3b(color);
	}
}

uint8_t* Frame::data() {
	if (storage_.empty()) {
		return nullptr;
	}

	return reinterpret_cast<uint8_t*>(storage_.data());
}

} // namespace r3d
