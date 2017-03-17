cmake_minimum_required(VERSION 3.6)
project(projekt1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    menu.cpp
        Tablica.h Tablica.cpp Lista.cpp Lista.h)
add_executable(projekt1 ${SOURCE_FILES})