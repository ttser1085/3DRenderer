#include "Loader.h"

#include <fstream>

namespace r3d {
Loader::Loader(const std::string& config_path)
	: config_(YAML::LoadFile(config_path)) {}

void Loader::Parse() {
	auto renderer = config_["renderer"];
	auto mode = renderer["mode"].as<std::string_view>();
	send(ParseRenderMode{mode});

	auto objects = config_["objects"];
	assert(objects.IsSequence());
	for (YAML::const_iterator it = objects.begin(); it != objects.end(); ++it) {
		auto pos = (*it)["position"];
		auto rotation = (*it)["rotation"];
		std::string path = (*it)["path"].as<std::string>();

		send(ParseBegin{Vec3{pos["x"].as<Float>(), pos["y"].as<Float>(),
							 pos["z"].as<Float>()},
						Vec3{rotation["angleX"].as<Float>(),
							 rotation["angleY"].as<Float>(),
							 rotation["angleZ"].as<Float>()}});
		parseObject(path);
		send(ParseEnd{});
	}
}

void Loader::parseObject(const std::string& path) {
	std::fstream stream(path);
	std::string word;
	while (stream >> word) {
		if (word == "v") {
			ParseVertex parse;
			stream >> parse.vertex.pos(0) >> parse.vertex.pos(1) >>
				parse.vertex.pos(2) >> parse.vertex.pos(3) >>
				parse.vertex.color.r >> parse.vertex.color.g >>
				parse.vertex.color.b;
			send(parse);
		} else if (word == "f") {
			ParseMesh parse;
			stream >> parse.vertices[0] >> parse.vertices[1] >>
				parse.vertices[2];
			send(parse);
		}
	}

	stream.close();
}

} // namespace r3d
