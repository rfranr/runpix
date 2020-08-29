cmake_minimum_required(VERSION 3.0)

project(runpix LANGUAGES C)

add_executable(runpix main.c)

target_link_libraries(runpix raylib)

install(TARGETS runpix RUNTIME DESTINATION bin)
