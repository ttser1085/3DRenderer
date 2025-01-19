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
	using frame_size_t = size_t;

public:
	enum Width : frame_size_t;
	enum Height : frame_size_t;

	Frame(Width width, Height height);

	void setColor(const Vec2s& pos, Color3b color);
	Color3b getColor(const Vec2s& pos) const;

	Width getWidth() const noexcept;
	Height getHeight() const noexcept;

	void clear(Color3b color = kBlack3b);

	uint8_t* data();

private:
	Width width_;
	Height height_;
	Storage storage_;
};

using FramePtr = std::shared_ptr<Frame>;

} // namespace r3d
