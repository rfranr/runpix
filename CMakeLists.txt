cmake_minimum_required(VERSION 3.16)
project(runpix)

set(CMAKE_CXX_STANDARD 11)

# Point to our own cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMakeModules)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake-conf")
find_package(SDL2 REQUIRED)
find_package(Log4cxx)

# Add global definitions
add_definitions("-Wall")
include_directories(${SDL2_INCLUDE_DIR})

add_executable(runpix main.cpp r/infrastructure/log/logger.h engine/sprite.h engine/sprite.cpp)
install(TARGETS runpix DESTINATION bin)
target_link_libraries(runpix ${SDL2_LIBRARIES} ${Log4cxx_LIBRARY} )
