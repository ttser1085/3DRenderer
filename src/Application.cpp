#include "Application.h"

namespace r3d {
Application::Application()
	: runtime_(RuntimeComponent::Width{800}, RuntimeComponent::Height{600},
			   "My window"),
	  model_(Frame::Width{800}, Frame::Height{600}), view_(runtime_),
	  controller_(model_) {
	model_.attachFramePort(view_.getFramePort());
	runtime_.attachEventPort(controller_.getEventPort());
}

void Application::run() { runtime_.run(); }

} // namespace r3d
