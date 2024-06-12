mkdir build
mkdir src
mkdir include
cat > CMakeLists.txt
cmake_minimum_required(VERSION 2.8.9)

project(project_name)

include_directories(include)

file(GLOB SOURCE "src/*.c")

add_executable(cpu_scheduling ${SOURCE})
