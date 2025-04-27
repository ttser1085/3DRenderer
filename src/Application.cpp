#include "Application.h"

#include "Controllers/KeyboardController.h"
#include "Controllers/MouseController.h"
#include "Controllers/TickController.h"

namespace r3d {

Application::Application()
	: runtime_("3D Renderer"), model_(makeSizePair(1440, 900)),
	  view_(runtime_.window()),
	  manager_(broker_, TickController, KeyboardController, MouseController) {
	model_.subscribe(&view_);
	broker_.subscribe(&model_);
	runtime_.ModelSender::subscribe(&manager_);
	runtime_.ViewSender::subscribe(&view_);
}

void Application::run() { runtime_.run(); }

} // namespace r3d
