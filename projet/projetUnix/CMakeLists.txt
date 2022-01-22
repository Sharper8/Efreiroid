cmake_minimum_required(VERSION 3.0.0)
project(SDLTEST VERSION 0.1.0 LANGUAGES C CXX)

file(COPY images/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/images/)

set(
    SRCS
    main.cpp
    framework.cpp
)

set(
    HEADER
    framework.hpp
)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

<<<<<<< HEAD
add_executable(SDLTEST WIN32 ${SRCS} ${HEADER})
=======
add_executable(SDLTEST ${SRCS} ${HEADER})
>>>>>>> e2e4c60c10fa4186fa5b91e224d00a7c24e4e5c6
target_link_libraries(SDLTEST ${SDL2_LIBRARIES})
