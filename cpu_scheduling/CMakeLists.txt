cmake_minimum_required(VERSION 2.8.9)

project(cpu_scheduling)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(cpu_scheduling ${SOURCES})
