option(BUILD_DOC "Build documentation" ON)

cmake_minimum_required(VERSION 3.16)
project(runpix)

set(CMAKE_CXX_STANDARD 11)

# Point to our own cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMakeModules)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake-conf")
find_package(Doxygen)
find_package(SDL2 REQUIRED)
find_package(Log4cxx REQUIRED)

# Documentation
if (DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_SOURCE_DIR}/docs/Doxyfile.in)

    message("Doxygen build started")

    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_IN}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)


# Add global definitions
add_definitions("-Wall")
include_directories(${SDL2_INCLUDE_DIR})

add_executable(runpix 
	main.cpp 
	r/infrastructure/log/logger.h 
	r/infrastructure/log/logger.cpp 
	r/infrastructure/graphics/graphics.h 
	engine/sprite.h 
	engine/sprite.cpp)
install(TARGETS runpix DESTINATION bin)
target_link_libraries(runpix ${SDL2_LIBRARIES} ${Log4cxx_LIBRARY} )
