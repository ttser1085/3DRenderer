#include "Renderer.h"

#include "Brush.h"
#include "Clipping.h"

namespace r3d {

// Renderer

Frame Renderer::makeFrame(const Camera& camera, const Scene& scene) const {
	Frame frame(camera.targetSize());
	frame.clear(kBlack3b);

	Brush brush(std::move(frame));

	for (const Object& object : scene.objects()) {
		for (auto proxy : object) {
			// TODO: clipping
			Mesh mesh{Vertex{proxy.position(0), proxy.color(0)},
					  Vertex{proxy.position(1), proxy.color(1)},
					  Vertex{proxy.position(2), proxy.color(2)}};

			for (inttypes::Index i = 0; i < 3; ++i) {
				mesh.vertices[i].pos = linalg::homoNormalized(
					camera.projection(camera.lookAt(mesh.vertices[i].pos)));
			}

			brush.drawMesh(mesh);
		}
	}

	return brush.release();
}

} // namespace r3d
