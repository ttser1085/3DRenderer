#include "Application.h"

namespace r3d {
Application::Application()
	: runtime_("3D Renderer"), model_(Width{1280}, Height{720}),
	  view_(runtime_.window()), controller_(model_) {
	model_.attachFramePort(view_.framePort());
	runtime_.attachEventPort(controller_.eventPort());
}

void Application::run() { runtime_.run(); }

} // namespace r3d
