#include "Renderer.h"

#include "Clipping.h"
#include "Drawer.h"

namespace r3d {

// Renderer

Frame Renderer::makeFrame(const Camera& camera, const Scene& scene) const {
	Frame frame(camera.targetSize());
	frame.clear(kBlack3b);

	BorderTest border_test(makeSizePair(0, 0), frame.size());
	DepthTest depth_test(frame.size());

	Drawer brush(std::move(frame),
				 conjunction(std::move(border_test), std::move(depth_test)));

	for (const Object& object : scene.objects()) {
		for (auto proxy : object) {
			// TODO: clipping
			Mesh mesh{Vertex{proxy.position(0), proxy.color(0)},
					  Vertex{proxy.position(1), proxy.color(1)},
					  Vertex{proxy.position(2), proxy.color(2)}};

			for (Index i = 0; i < 3; ++i) {
				mesh.vertices[i].pos = linalg::homoNormalized(
					camera.projection(camera.lookAt(mesh.vertices[i].pos)));
			}

			brush.drawMesh(mesh);
		}
	}

	return brush.release();
}

} // namespace r3d
