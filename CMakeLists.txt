cmake_minimum_required(VERSION 3.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(renegl C CXX)

# glfw
find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})

# glad
set(GLAD_SOURCES_DIR "${PROJECT_SOURCE_DIR}/external/glad/")
add_subdirectory("${GLAD_SOURCES_DIR}/cmake" glad_cmake)
glad_add_library(lglad SHARED API gl:core=4.1)

set(SOURCE_FILES src/main.cpp)
configure_file(src/vert.glsl ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(src/frag.glsl ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)


add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PUBLIC lglad glfw)
