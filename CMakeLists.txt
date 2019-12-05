cmake_minimum_required(VERSION 3.14)

project(Proyecto_Final C)

set(CMAKE_C_STANDARD 99)

include_directories(includes)

add_executable(Main Proyecto/Main.c Proyecto/libreria.c Proyecto/libreria.h)