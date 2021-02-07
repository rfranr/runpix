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
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_SOURCE_DIR}/docs/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
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
