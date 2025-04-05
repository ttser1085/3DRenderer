#include "ZBuffer.h"

namespace r3d {

ZBuffer::ZBuffer(SizePair size)
	: Base(size, std::numeric_limits<Float>::infinity()) {}

bool ZBuffer::set(SizePair pos, Float value) {
	if (Base::get(pos) > value) {
		Base::get(pos) = value;
		return true;
	}

	return false;
}

} // namespace r3d
