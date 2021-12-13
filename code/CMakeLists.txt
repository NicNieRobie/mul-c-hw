cmake_minimum_required(VERSION 3.20)
project(mul_c_hw C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS -pthread)

add_executable(mul_c_hw main.c talker.h talker.c container.h container.c name_generation.h name_generation.c)
