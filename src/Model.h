#pragma once

#include "Core/Core.h"
#include "CoreEvent.h"

namespace r3d {
class Model {

	using SizePair = inttypes::SizePair;

	using FrameOutput =
		NSLibrary::CObservableData<FrozenFrame, NSLibrary::CByValue>;
	using FrameInput = NSLibrary::CObserver<FrozenFrame, NSLibrary::CByValue>;

	using Events = std::vector<CoreEvent>;
	using EventOutput = NSLibrary::CObservableData<Events, NSLibrary::CByReference>;
	using EventInput = NSLibrary::CColdInput<Events, NSLibrary::CByReference>;

public:
	explicit Model(SizePair target_size_);

	void subscribe(FrameInput* obs);

	EventInput* eventPort();

private:
	void handle(const Events& events);

	Core core_;
	Vec3 movement_dir_;
	FrameOutput frame_out_;
	EventInput event_in_;
};

} // namespace r3d
