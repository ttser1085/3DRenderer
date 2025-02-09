#include "Frame.h"

namespace r3d {

Frame::Frame(SizePair size) : size_(size), storage_(size.x * size.y) {}

void Frame::setColor(SizePair pos, Color3b color) {
	storage_[pos.y * size_.x + pos.x] =
		Color4b::fromColor3b(color);
}

Color3b Frame::getColor(SizePair pos) const {
	return Color3b::fromColor4b(storage_[pos.y * size_.x + pos.x]);
}

Frame::Width Frame::width() const noexcept { return size_.x; }

Frame::Height Frame::height() const noexcept { return size_.y; }

void Frame::clear(Color3b color) {
	std::fill(storage_.begin(), storage_.end(), Color4b::fromColor3b(color));
}

const inttypes::Byte* Frame::data() const {
	if (storage_.empty()) {
		return nullptr;
	}

	return reinterpret_cast<const inttypes::Byte*>(storage_.data());
}

} // namespace r3d
