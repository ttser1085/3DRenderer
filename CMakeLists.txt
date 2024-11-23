cmake_minimum_required(VERSION 3.10)
project(3DRenderer)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(submodules/eigen)
# add_subdirectory(submodules/Library)
add_subdirectory(submodules/SFML)

include_directories(submodules/eigen/)
include_directories(submodules/Library/Observer3)
include_directories(submodules/SFML/include)

set(CMAKE_CXX_COMPILER /usr/bin/clang++-17)

set(SOURCE_DIR src)
file(GLOB SOURCES "${SOURCE_DIR}/*.cpp")

add_executable(renderer ${SOURCES})
target_link_libraries(renderer PRIVATE sfml-system sfml-window sfml-graphics)
