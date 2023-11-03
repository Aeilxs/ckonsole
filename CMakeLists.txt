cmake_minimum_required(VERSION 3.10)

project(ckonsole)

include_directories(src/include)
file(GLOB SOURCES "src/*.c" "src/mods/*.c")

add_executable(ckonsole ${SOURCES})