cmake_minimum_required(VERSION 3.6)
project(projekt1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    menu.cpp
        Tablica.h Tablica.cpp Kopiec.cpp Kopiec.h Testy.cpp Testy.h Lista.cpp Lista.h DrzewoRB.cpp DrzewoRB.h)
add_executable(projekt1 ${SOURCE_FILES})