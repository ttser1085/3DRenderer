#pragma once

#include "Communication.h"
#include "Core/Core.h"
#include "Messages/Core.h"
#include "Messages/FrozenFrame.h"
#include "CoreConfig.h"

namespace r3d {

class Model {
	using Events = std::vector<CoreEvent>;
	using EventInput = ColdStreamInput<CoreEvent>;
	using Output = Output<FrozenFrame, ByVal>;

public:
	Model();
			
	void initFromConfig(CoreConfig config);

	EventInput* input();
	void subscribe(Input<FrozenFrame, ByVal>*);

private:
	void handle(const Events& events);

	Core core_;
	Vec3 movement_dir_;

	EventInput input_;
	Output output_;
};

} // namespace r3d
