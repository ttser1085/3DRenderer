#include "Scene.h"

namespace r3d {

Scene::Scene() {}

const std::vector<Object>& Scene::objects() const { return objects_; }

void Scene::addObject(Object object) {
	objects_.emplace_back(std::move(object));
}

void Scene::addObjects(std::vector<Object> objects) {
	if (objects_.empty()) {
		objects_ = std::move(objects);
		return;
	}

	for (auto& obj : objects) {
		objects_.emplace_back(std::move(obj));
	}
}

void Scene::clear() {
	objects_.clear();
}

} // namespace r3d
