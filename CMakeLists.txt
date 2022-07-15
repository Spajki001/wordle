cmake_minimum_required(VERSION 3.3.2)

project(Wordle C)

set(CMAKE_C_STANDARD 99)

file(GLOB_RECURSE SOURCE_LIST "src/*.c")

add_executable(Wordle "${SOURCE_LIST}")