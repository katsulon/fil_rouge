set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

cmake_minimum_required(VERSION 3.14)

project(goloviatinski_fil_rouge)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(goloviatinski_fil_rouge main.cpp ${SRC_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "main")

target_include_directories(goloviatinski_fil_rouge PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/hero)