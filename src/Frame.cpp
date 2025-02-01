#include "Frame.h"

namespace r3d {

Frame::Frame(Width width, Height height)
	: width_(width), height_(height),
	  storage_(static_cast<screen_size_t>(width) *
			   static_cast<screen_size_t>(height)) {}

void Frame::setColor(const SizePair& pos, Color3b color) {
	storage_[pos.second * width_ + pos.first] = Color4b::fromColor3b(color);
}

Color3b Frame::getColor(const SizePair& pos) const {
	return Color3b::fromColor4b(storage_[pos.second * width_ + pos.first]);
}

Width Frame::width() const noexcept { return width_; }

Height Frame::height() const noexcept { return height_; }

void Frame::clear(Color3b color) {
	std::fill(storage_.begin(), storage_.end(), Color4b::fromColor3b(color));
}

const uint8_t* Frame::data() const {
	if (storage_.empty()) {
		return nullptr;
	}

	return reinterpret_cast<const uint8_t*>(storage_.data());
}

} // namespace r3d
