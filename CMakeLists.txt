cmake_minimum_required(VERSION 3.31)
project(o3)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG        40626af88bd7df9a5fb80be7b25ac85b122d6c21) # 11.2.0
FetchContent_MakeAvailable(fmt)

find_package(verilator REQUIRED)

add_executable(o3 main.cpp)
verilate(o3 SOURCES rtl/top.sv)


target_link_libraries(o3 PRIVATE fmt::fmt)