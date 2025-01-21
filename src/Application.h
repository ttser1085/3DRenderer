#pragma once

#include "Model.h"
#include "View.h"
#include "Controller.h"
#include "RuntimeComponent.h"

namespace r3d {

class Application {
public:
    Application();

    void run();

private:
    RuntimeComponent runtime_;

    Model model_;
    View view_;
    Controller controller_;
};

} // namespace r3d
