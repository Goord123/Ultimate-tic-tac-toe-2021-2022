cmake_minimum_required(VERSION 3.23)
project(prog C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(prog
        main.c
        funcs.c
        funcs.h)
