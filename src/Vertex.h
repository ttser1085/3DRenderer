#pragma once

#include "Color.h"
#include "Linalg/LinalgBase.h"

namespace r3d {

using linalg::Vec3;
using linalg::Vec4;

struct Vertex {
    linalg::Vec4 pos;
    Color3f color;
};


} // namespace r3d
