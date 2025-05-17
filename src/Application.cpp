#include "Application.h"

#include "Loader.h"

namespace r3d {

Application::Application(int argc, char* argv[])
	: runtime_("3D Renderer"), view_(runtime_.window()) {
	model_.subscribe(view_.frameInput());
	broker_.subscribe(model_.input());

	tick_controller.subscribe(broker_.updateInput());
	mouse_controller.subscribe(broker_.rotateInput());
	key_controller.subscribe(broker_.moveInput());

	runtime_.subscribe(tick_controller.input());
	runtime_.subscribe(mouse_controller.input());
	runtime_.subscribe(key_controller.input());
	runtime_.subscribe(view_.resizeInput());

	if (argc >= 2) {
		Loader loader(argv[1]);
		CoreConfig config = loader.parseCoreConfig();
		model_.initFromConfig(std::move(config));
	}
}

void Application::run() { runtime_.run(); }

} // namespace r3d
