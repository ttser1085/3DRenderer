#include "Scene.h"

namespace r3d {

std::vector<Object>& r3d::Scene::objects() {
	return objects_;
}

const std::vector<Object>& Scene::objects() const {
	return objects_;
}

} // namespace r3d
