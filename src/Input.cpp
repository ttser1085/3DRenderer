#include <Input.h>

namespace r3d {

void Input::send(const ModelEvent& event) {
    ModelSender::set(event);
}

void Input::send(const ViewEvent& event) {
    ViewSender::set(event);
}

} // namespace r3d
