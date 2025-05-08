cmake_minimum_required(VERSION 3.31)
project(o3)

set(CMAKE_CXX_STANDARD 20)

find_package(verilator REQUIRED)

add_executable(o3 main.cpp)
