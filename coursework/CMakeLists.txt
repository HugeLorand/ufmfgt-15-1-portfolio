cmake_minimum_required(VERSION 4.2)
project(coursework C)

set(CMAKE_C_STANDARD 99)

add_executable(coursework main.c
        waveform.c
        io.c)
