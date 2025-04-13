#pragma once

#include "Model.h"
#include "View.h"
#include "Controller.h"
#include "Runtime.h"
#include "Broker.h"

namespace r3d {

class Application {
public:
    Application();

    void run();

private:
    Runtime runtime_;

    Model model_;
    View view_;
    Controller controller_;
    Broker broker_;
};

} // namespace r3d
