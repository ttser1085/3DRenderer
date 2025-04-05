#pragma once

#include "Color.h"
#include "RectBuffer.h"

#include <Observer.h>
#include <memory>
#include <vector>

namespace r3d {

class Frame final : public RectBuffer<Color4b> {
	using Base = RectBuffer<Color4b>;

public:
	explicit Frame(SizePair size);

	void setColor(SizePair pos, Color3b color);

	Color3b getColor(SizePair pos) const;

	void clear(Color3b color = kBlack3b);

	const Byte* data() const;
};

using FrozenFrame = std::shared_ptr<const Frame>;

} // namespace r3d
