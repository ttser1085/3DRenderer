#pragma once

#include "Communication.h"
#include "ModelEvent.h"

#include <string>

namespace r3d {

class Loader : public Sender<ModelEvent, ByRef> {
public:
	void ParseObject(const std::string& path, const Vec3& pos);
};

} // namespace r3d
