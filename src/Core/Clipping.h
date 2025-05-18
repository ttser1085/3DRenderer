#pragma once

#include "Mesh.h"
#include "Object.h"

namespace r3d {

std::vector<Mesh> clip(ProxyMesh mesh, const lalg::Plane& plane);
std::vector<Mesh> clip(const Mesh& mesh, const lalg::Plane& plane);

std::vector<Mesh> clip(ProxyMesh mesh, const std::vector<lalg::Plane>& planes);
std::vector<Mesh> clip(const Mesh& mesh, const std::vector<lalg::Plane>& planes);

} // namespace r3d
