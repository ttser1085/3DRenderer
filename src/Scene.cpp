#include "Scene.h"

namespace r3d {

Scene::Scene() {
	initObjects();
}

std::vector<Object>& r3d::Scene::objects() {
	return objects_;
}

const std::vector<Object>& Scene::objects() const {
	return objects_;
}

// Пока так, потом чтение из файлика сделаю
void Scene::initObjects() {
	Object object;
	// addVertex ...
	// addMesh ...

	objects_.emplace_back(std::move(object));
}

} // namespace r3d
