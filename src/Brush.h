#pragma once

#include "Frame.h"
#include "Object.h"

namespace r3d {

class Brush {

    using Canvas = FramePtr;

public:
    Brush(Canvas canvas);

    void drawPoint(const Vec2f& pos, const Color3f& color);
    // void drawMesh;

private:
    Canvas canvas_;
};

} // namespace r3d
