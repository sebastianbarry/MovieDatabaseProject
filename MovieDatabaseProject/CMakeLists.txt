cmake_minimum_required(VERSION 3.17)
project(MovieDatabaseProject)

set(CMAKE_CXX_STANDARD 11)

add_executable(MovieDatabaseProject main.cpp picture.cpp actor.cpp actor.h picture.h)
