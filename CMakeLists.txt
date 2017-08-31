cmake_minimum_required(VERSION 3.6)
project(ADS_2017)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c PrimAvecSources.c main.h KruskalAvecSources.c)
add_executable(ADS_2017 ${SOURCE_FILES})