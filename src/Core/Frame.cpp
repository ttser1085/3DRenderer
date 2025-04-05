#include "Frame.h"

namespace r3d {

Frame::Frame(SizePair size) : Base(size) {}

void Frame::setColor(SizePair pos, Color3b color) {
	Base::get(pos) = Color4b::fromColor3b(color);
}

Color3b Frame::getColor(SizePair pos) const {
	return Color3b::fromColor4b(RectBuffer<Color4b>::get(pos));
}

void Frame::clear(Color3b color) { Base::clear(Color4b::fromColor3b(color)); }

const Frame::Base::Byte* Frame::data() const { return Base::data(); }

} // namespace r3d
