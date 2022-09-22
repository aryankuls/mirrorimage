cmake_minimum_required(VERSION 3.5.1)

# set a project name
project(mirrorImg)

set(SOURCES src/mirror_left.cpp src/mirror_upwards.cpp)
set(HEADER_FILES inc/mirror.h)
add_library(srcLib STATIC ${SOURCES} ${HEADER_FILES})

set(CMAKE_CXX_STANDARD 14)

# Include header directory
include_directories(inc)

# Generate a binary
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} srcLib)
