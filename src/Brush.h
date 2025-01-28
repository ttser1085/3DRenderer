#pragma once

#include "Frame.h"
#include "Object.h"

namespace r3d {

class Brush {

    using Canvas = Frame;

public:
    Brush(Canvas&& canvas);

    void drawPoint(const Vec2f& pos, const Color3f& color);
    // void drawLine;
    // void drawMesh;
    // void fillMesh;

    Canvas&& release();

private:
    Canvas canvas_;
};

} // namespace r3d
