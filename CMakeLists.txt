cmake_minimum_required(VERSION 3.29)
project(main C)

set(CMAKE_C_STANDARD 11)

add_executable(main main.c
        generate-random-coordianates.c
        header.h
        two-opt.c
        help.c
        get-coordinates-from-terminal.c
        path-finding.c
        nearest-neighbor.c)


