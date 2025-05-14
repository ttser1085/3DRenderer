#pragma once

#include "Communication.h"
#include "Core/Core.h"
#include "CoreEvent.h"
#include "CoreConfig.h"

namespace r3d {

class Model : public Sender<FrozenFrame, ByVal>,
			  public ColdStreamReceiver<CoreEvent> {
	using Events = std::vector<CoreEvent>;
	using EventReceiver = ColdStreamReceiver<CoreEvent>;

public:
	Model();
			
	void initFromConfig(CoreConfig config);

private:
	void handle(const Events& events);

	Core core_;
	Vec3 movement_dir_;
};

} // namespace r3d
