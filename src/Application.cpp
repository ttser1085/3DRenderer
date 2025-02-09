#include "Application.h"

namespace r3d {
Application::Application()
	: runtime_("3D Renderer"), model_(inttypes::makeSizePair(1440, 900)),
	  view_(runtime_.window()), controller_(model_) {
	model_.subscribe(view_.framePort());
	runtime_.subscribe(controller_.eventPort());
	runtime_.subscribe(view_.eventPort());
}

void Application::run() { runtime_.run(); }

} // namespace r3d
