#pragma once

#include "Color.h"
#include "Linalg.h"

#include <Observer.h>
#include <memory>
#include <utility>
#include <vector>

namespace r3d {

class Frame {

	using Storage = std::vector<Color4b>;

public:
	Frame(Width width, Height height);

	void setColor(const Vec2s& pos, Color3b color);
	Color3b getColor(const Vec2s& pos) const;

	Width width() const noexcept;
	Height height() const noexcept;

	void clear(Color3b color = kBlack3b);

	const uint8_t* data() const;

private:
	Width width_;
	Height height_;
	Storage storage_;
};

using FrozenFrame = std::shared_ptr<const Frame>;

} // namespace r3d
