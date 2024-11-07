cmake_minimum_required(VERSION 3.28)
project(sources C)

set(CMAKE_C_STANDARD 99)

add_executable(sources main.c
        structures.h
        neurone.c
        neurone.h
        couche.c
        couche.h
        reseau.c
        reseau.h)
