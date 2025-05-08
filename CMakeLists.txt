cmake_minimum_required(VERSION 3.10)
project(3DRenderer)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(submodules/eigen)
# add_subdirectory(submodules/Library)
add_subdirectory(submodules/SFML)
add_subdirectory(submodules/yaml-cpp)

include_directories(submodules/eigen/)
include_directories(submodules/Library/Observer3)
include_directories(submodules/SFML/include)
include_directories(submodules/yaml-cpp/include)

set(SOURCE_DIR src)
file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.cpp")

include_directories(src/)

add_executable(renderer ${SOURCES})
target_compile_features(renderer PRIVATE cxx_std_20)
target_link_libraries(renderer PRIVATE sfml-system sfml-window sfml-graphics yaml-cpp)
