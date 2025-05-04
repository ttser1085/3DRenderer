#pragma once

#include "Broker.h"
#include "ModelEvent.h"

namespace r3d {

class LoadController {
public:
	void operator()(Broker& broker, const ParseBegin& begin) {
		Vec3 rotation{lalg::toRadians(begin.rotation(0)),
					  lalg::toRadians(begin.rotation(1)),
					  lalg::toRadians(begin.rotation(2))};
		broker.handle(BeginObject{begin.pos, rotation});
	}

	void operator()(Broker& broker, const ParseEnd end) {
		broker.handle(EndObject{});
	}

	void operator()(Broker& broker, const ParseVertex& pos) {
		broker.handle(AddVertex{pos.vertex});
	}

	void operator()(Broker& broker, const ParseMesh& mesh) {
		broker.handle(
			AddMesh{mesh.vertices[0], mesh.vertices[1], mesh.vertices[2]});
	}

	void operator()(Broker& broker, ParseRenderMode parsed) {
		if (parsed.mode == "full") {
			broker.handle(SetRenderMode{Renderer::RenderMode::FULL});
		} else if (parsed.mode == "skeleton") {
			broker.handle(SetRenderMode{Renderer::RenderMode::SKELETON});
		} else if (parsed.mode == "bordered") {
			broker.handle(SetRenderMode{Renderer::RenderMode::BORDERED});
		} else {
			throw std::invalid_argument("invalid mode: " + std::string(parsed.mode));
		}
	}
};

} // namespace r3d
