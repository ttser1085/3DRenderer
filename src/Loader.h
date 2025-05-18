#pragma once

#include "CoreConfig.h"

#include <SFML/Graphics.hpp>
#include <yaml-cpp/yaml.h>

#include <string_view>

namespace r3d {

class Loader {
public:
	explicit Loader(const std::string& config_path);

	CoreConfig parseCoreConfig();
	sf::Font parseFont();

private:
	Object parseObject(const std::string& path);

	YAML::Node config_;
};

} // namespace r3d
