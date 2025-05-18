#pragma once

#include "Core/Frame.h"

#include <memory>

namespace r3d {

class FrozenFrame {
public:
    FrozenFrame() = default;

    FrozenFrame(Frame&& frame) {
        frame_ = std::make_shared<const Frame>(std::move(frame));
    }

	const Frame* operator->() const { return frame_.get(); }

	bool hasData() const { return frame_ != nullptr; }

private:
	std::shared_ptr<const Frame> frame_;
};

} // namespace r3d
