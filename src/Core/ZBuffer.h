#pragma once

#include "Linalg/LinalgBase.h"
#include "RectBuffer.h"

namespace r3d {

using lalg::Float;

class ZBuffer final : public RectBuffer<Float> {
	using Base = RectBuffer<Float>;

public:
	explicit ZBuffer(SizePair size);

	bool set(SizePair pos, Float value);
};

} // namespace r3d
