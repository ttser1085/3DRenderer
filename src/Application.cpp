#include "Application.h"

#include "Loader.h"

namespace r3d {

Application::Application(int argc, char* argv[])
	: runtime_("3D Renderer"), view_(runtime_.window()) {
	model_.subscribe(&view_);
	broker_.subscribe(&model_);

	tick_controller.subscribe(&broker_);
	mouse_controller.subscribe(&broker_);
	key_controller.subscribe(&broker_);

	runtime_.TickSender::subscribe(&tick_controller);
	runtime_.MouseSender::subscribe(&mouse_controller);
	runtime_.KeySender::subscribe(&key_controller);

	runtime_.ViewSender::subscribe(&view_);

	if (argc >= 2) {
		Loader loader(argv[1]);
		CoreConfig config = loader.parseCoreConfig();
		model_.initFromConfig(std::move(config));
	}
}

void Application::run() { runtime_.run(); }

} // namespace r3d
