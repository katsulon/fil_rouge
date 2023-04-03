cmake_minimum_required(VERSION 3.10...3.26)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

project(goloviatinski_fil_rouge)

find_package(SDL2 REQUIRED)
include_directories(goloviatinski_fil_rouge ${SDL2_INCLUDE_DIRS})

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(goloviatinski_fil_rouge main.cpp ${SRC_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "main")

target_include_directories(goloviatinski_fil_rouge PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/hero)
target_link_libraries(goloviatinski_fil_rouge ${SDL2_LIBRARIES})