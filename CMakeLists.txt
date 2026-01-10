cmake_minimum_required(VERSION 3.15)


project(ZOOMANAGER VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    src/main.cpp
    src/Animal.cpp
    src/Bird.cpp
    src/Date.cpp
    src/Eagle.cpp
    src/Lion.cpp
    src/Mammal.cpp
    src/Reptile.cpp
    src/Snake.cpp
    src/ZooManager.cpp
    src/DataIO.cpp
)

add_executable(ZOOMANAGER ${SOURCES})

target_include_directories(ZOOMANAGER PUBLIC include)