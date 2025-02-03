#pragma once

#include "Color.h"

#include <Observer.h>
#include <memory>
#include <vector>

namespace r3d {

class Frame {

	using Width = inttypes::Width;
	using Height = inttypes::Height;
	using SizePair = inttypes::SizePair;

	using Storage = std::vector<Color4b>;

public:
	Frame(Width width, Height height);

	void setColor(const SizePair& pos, Color3b color);
	Color3b getColor(const SizePair& pos) const;

	Width width() const noexcept;
	Height height() const noexcept;

	void clear(Color3b color = kBlack3b);

	const inttypes::Byte* data() const;

private:
	Width width_;
	Height height_;
	Storage storage_;
};

using FrozenFrame = std::shared_ptr<const Frame>;

} // namespace r3d
