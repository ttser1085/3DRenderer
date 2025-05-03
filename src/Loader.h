#pragma once

#include "Communication.h"
#include "ModelEvent.h"

#include <yaml-cpp/yaml.h>

#include <string_view>

namespace r3d {

class Loader : public Sender<ModelEvent, ByRef> {
public:
	explicit Loader(const std::string& config_path);

	void Parse();

private:
	void parseObject(const std::string& path);

	YAML::Node config_;
};

} // namespace r3d
