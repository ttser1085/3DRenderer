#include "Scene.h"

namespace r3d {

Scene::Scene() { initObjects(); }

std::vector<Object>& r3d::Scene::objects() { return objects_; }

const std::vector<Object>& Scene::objects() const { return objects_; }

// Пока так, потом чтение из файлика сделаю
void Scene::initObjects() {
	Object object(Vec3{0.0f, 0.0f, -7.0f});
	object.addVertex(Vertex{Vec4{0.0f, 0.0f, 0.0f, 1.0f}, kGreen3f});
	object.addVertex(Vertex{Vec4{1.0f, 0.0f, 0.0f, 1.0f}, kBlue3f});
	object.addVertex(Vertex{Vec4{0.0f, 1.0f, 0.0f, 1.0f}, kBlue3f});
	object.addVertex(Vertex{Vec4{1.0f, 1.0f, 0.0f, 1.0f}, kBlue3f});

	object.addVertex(Vertex{Vec4{0.0f, 0.0f, 1.0f, 1.0f}, kRed3f});
	object.addVertex(Vertex{Vec4{1.0f, 0.0f, 1.0f, 1.0f}, kRed3f});
	object.addVertex(Vertex{Vec4{0.0f, 1.0f, 1.0f, 1.0f}, kRed3f});
	object.addVertex(Vertex{Vec4{1.0f, 1.0f, 1.0f, 1.0f}, kRed3f});

	object.addMesh(0, 2, 1);
	object.addMesh(1, 2, 3);

	object.addMesh(1, 5, 7);
	object.addMesh(1, 7, 3);

	object.addMesh(0, 4, 2);
	object.addMesh(4, 6, 2);

	object.addMesh(0, 1, 5);
	object.addMesh(0, 5, 4);

	object.addMesh(2, 3, 6);
	object.addMesh(3, 7, 6);

	object.addMesh(6, 5, 4);
	object.addMesh(6, 7, 5);

	object.rotate(linalg::toRadians(30.0f), Vec3::UnitY());

	objects_.emplace_back(std::move(object));
}

} // namespace r3d
