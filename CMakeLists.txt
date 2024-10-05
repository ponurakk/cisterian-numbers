cmake_minimum_required(VERSION 3.18)
project(cisterian-numbers VERSION 0.1.0 LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_FLAGS_DEBUG "-g")

set(SOURCE_FILES
  src/main.c
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

add_subdirectory(libs/glad/)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad)
