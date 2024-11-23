#pragma once

#include "Color.h"
#include "Linalg.h"

#include <Observer.h>
#include <memory>
#include <utility>
#include <vector>

namespace r3d {

class Frame {

	using Storage = std::vector<Color4>;
	using frame_size_t = size_t;

public:
	enum Width : frame_size_t;
	enum Height : frame_size_t;

	Frame(Width width, Height height);

	void setColor(const Vec2s& pos, Color3 color);
	Color3 getColor(const Vec2s& pos) const;

	Width getWidth() const noexcept;
	Height getHeight() const noexcept;

	void changeSize(const Vec2s& new_size);

	void clear(Color3 color = kBlack3);

	uint8_t* data();

private:
	Width width_;
	Height height_;
	Storage storage_;
};

using FramePtr = std::shared_ptr<Frame>;

using FrameObservable =
	NSLibrary::CObservableData<FramePtr, NSLibrary::CByValue>;
using FrameObserver = NSLibrary::CObserver<FramePtr, NSLibrary::CByValue>;
using FrameColdInput = NSLibrary::CColdInput<FramePtr, NSLibrary::CByValue>;

static_assert(std::is_same_v<FrameObservable::CReturn, FramePtr>);

} // namespace r3d
