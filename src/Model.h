#pragma once

#include "Core/Core.h"
#include "CoreEvent.h"

namespace r3d {
class Model {

	using SizePair = inttypes::SizePair;

	using FrameOutput =
		NSLibrary::CObservableData<FrozenFrame, NSLibrary::CByValue>;
	using FrameInput = NSLibrary::CObserver<FrozenFrame, NSLibrary::CByValue>;

public:
	explicit Model(SizePair target_size_);

	void subscribe(FrameInput* obs);

	void Handle(std::vector<CoreEvent> events);

private:
	Core core_;
	Vec3 movement_dir_;
	FrameOutput frame_out_;
};

} // namespace r3d
