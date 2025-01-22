#include "Application.h"

namespace r3d {
Application::Application()
	: runtime_(Width{800}, Height{600}, "My window"),
	  model_(Width{800}, Height{600}), view_(runtime_), controller_(model_) {
	model_.attachFramePort(view_.getFramePort());
	runtime_.attachEventPort(controller_.getEventPort());
}

void Application::run() { runtime_.run(); }

} // namespace r3d
