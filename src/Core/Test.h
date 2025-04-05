#include "Vertex.h"
#include "ZBuffer.h"

namespace r3d {

class DepthTest {
public:
	DepthTest(inttypes::SizePair size) : zbuff_(size) {}

	bool operator()(inttypes::SizePair pos, const Vertex& vertex) {
		return zbuff_.set(pos, vertex.pos(2));
	}

private:
	ZBuffer zbuff_;
};

// class AlphaTest {
// public:
// 	AlphaTest(linalg::Float threshold) : threshold_(threshold) {}

// 	bool operator()(inttypes::SizePair pos, const Vertex& vertex) {
// 		return vertex.color.a > threshold_;
// 	}

// private:
// 	linalg::Float threshold_;
// };

} // namespace r3d
