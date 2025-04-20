#include "ZBuffer.h"

namespace r3d {

ZBuffer::ZBuffer(SizePair size) : Base(size, lalg::kInfinity) {}

bool ZBuffer::set(SizePair pos, Float value) {
	if (Base::get(pos) > value) {
		Base::get(pos) = value;
		return true;
	}

	return false;
}

} // namespace r3d
