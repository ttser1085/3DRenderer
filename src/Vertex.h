#pragma once

#include "Color.h"
#include "Linalg/LinalgBase.h"

namespace r3d {

struct Vertex {
    linalg::Vec4 pos;
    Color3f color;
};


} // namespace r3d
