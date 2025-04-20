#include "Application.h"

namespace r3d {
Application::Application()
	: runtime_("3D Renderer"), model_(inttypes::makeSizePair(1440, 900)),
	  view_(runtime_.window()), controller_(broker_) {
	model_.subscribe(&view_);
	broker_.subscribe(&model_);
	runtime_.ModelSender::subscribe(&controller_);
	runtime_.ViewSender::subscribe(&view_);
}

void Application::run() { runtime_.run(); }

} // namespace r3d
