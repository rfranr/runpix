cmake_minimum_required(VERSION 3.16)
project(runpix)

set(CMAKE_CXX_STANDARD 11)

# Point to our own cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMakeModules)

# Find SDL2
find_package(SDL2 REQUIRED)

# Add global definitions
add_definitions("-Wall")
include_directories(${SDL2_INCLUDE_DIR})

add_executable(runpix main.cpp engine/sprite.h engine/sprite.cpp)
install(TARGETS runpix DESTINATION bin)
target_link_libraries(runpix ${SDL2_LIBRARIES})
