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

	Drawer drawer(std::move(frame),
				  conjunction(std::move(border_test), std::move(depth_test)),
				  OptimizedShader{}, FullLineShader{});

	std::vector<lalg::Plane> planes = camera.planes();
	for (const Object& object : scene.objects()) {
		for (auto proxy : object) {
			for (auto& mesh : clip(proxy, planes)) {
				for (Index i = 0; i < 3; ++i) {
					mesh[i].pos = lalg::homoNormalized(
						camera.projection(camera.lookAt(mesh[i].pos)));
				}

				if (mode_ == RenderMode::FULL) {
					drawer.fillMesh(mesh);
				} else if (mode_ == RenderMode::SKELETON) {
					drawer.drawMesh(mesh);
				} else if (mode_ == RenderMode::BORDERED) {
					drawer.fillMesh(mesh);
					drawer.drawMesh(mesh);
				} else {
					assert(false);
				}
			}
		}
	}

	return drawer.release();
}

void Renderer::setMode(RenderMode mode) { mode_ = mode; }

} // namespace r3d
