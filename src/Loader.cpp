#include "Loader.h"

#include <fstream>

namespace r3d {
Loader::Loader(const std::string& config_path)
	: config_(YAML::LoadFile(config_path)) {}

CoreConfig Loader::parseCoreConfig() {
	CoreConfig model_cfg;

	std::string mode = config_["renderer"]["mode"].as<std::string>();

	if (mode == "full") {
		model_cfg.mode = Renderer::RenderMode::FULL;
	} else if (mode == "bordered") {
		model_cfg.mode = Renderer::RenderMode::BORDERED;
	} else {
		model_cfg.mode = Renderer::RenderMode::SKELETON;
	}

	auto objects = config_["objects"];
	if (objects.IsSequence()) {
		for (YAML::const_iterator it = objects.begin(); it != objects.end();
			 ++it) {
			std::string path = (*it)["path"].as<std::string>();
			model_cfg.objects.emplace_back(parseObject(path));

			auto pos = (*it)["position"];
			auto rotation = (*it)["rotation"];

			model_cfg.objects.back().move(Vec3{pos["x"].as<Float>(),
											   pos["y"].as<Float>(),
											   pos["z"].as<Float>()});

			model_cfg.objects.back().rotate(Vec3{
				rotation["angleX"].as<Float>(), rotation["angleY"].as<Float>(),
				rotation["angleZ"].as<Float>()});
		}
	}

	return model_cfg;
}

sf::Font Loader::parseFont() {
	std::string font_path = config_["renderer"]["font"].as<std::string>();

	sf::Font font;
	font.openFromFile(font_path);

	return font;
}

Object Loader::parseObject(const std::string& path) {
	std::fstream stream(path);
	std::string word;

	Object obj;

	while (stream >> word) {
		if (word == "v") {
			Vertex vertex;
			stream >> vertex.pos(0) >> vertex.pos(1) >> vertex.pos(2) >>
				vertex.pos(3) >> vertex.color.r >> vertex.color.g >>
				vertex.color.b;
			obj.addVertex(vertex);
		} else if (word == "f") {
			Index vertices[3];
			stream >> vertices[0] >> vertices[1] >> vertices[2];
			obj.addMesh(vertices[0], vertices[1], vertices[2]);
		}
	}

	stream.close();
	return obj;
}

} // namespace r3d
