#pragma once

#include "Communication.h"
#include "Core/Core.h"
#include "CoreEvent.h"

namespace r3d {
class Model : public Sender<FrozenFrame, NSLibrary::CByValue>,
			  public ColdStreamReceiver<CoreEvent> {
	using Events = std::vector<CoreEvent>;
	using EventReceiver = ColdStreamReceiver<CoreEvent>;

public:
	explicit Model(SizePair target_size_);

private:
	void handle(const Events& events);

	Core core_;
	Vec3 movement_dir_;
};

} // namespace r3d
