#pragma once

#include "Broker.h"
#include "ModelEvent.h"

namespace r3d {

class LoadController {
public:
	void operator()(Broker& broker, const ParseBegin& begin) {
		broker.handle(BeginObject{begin.pos});
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
};

} // namespace r3d
