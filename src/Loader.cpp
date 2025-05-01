#include "Loader.h"

#include <fstream>

namespace r3d {

void Loader::ParseObject(const std::string& path, const Vec3& pos) {
	using lalg::Vec4;

	BaseType::set(ParseBegin{pos});

	std::fstream stream(path);
	std::string word;
	while (stream >> word) {
		if (word == "v") {
			ParseVertex parse;
			stream >> parse.vertex.pos(0) >> parse.vertex.pos(1) >>
				parse.vertex.pos(2) >> parse.vertex.pos(3) >>
				parse.vertex.color.r >> parse.vertex.color.g >>
				parse.vertex.color.b;
			BaseType::set(parse);
		} else if (word == "f") {
			ParseMesh parse;
			stream >> parse.vertices[0] >> parse.vertices[1] >>
				parse.vertices[2];
			BaseType::set(parse);
		}
	}

	BaseType::set(ParseEnd{});

	stream.close();
}

} // namespace r3d
