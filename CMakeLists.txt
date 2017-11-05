cmake_minimum_required(VERSION 3.8)
include(ExternalProject)

project(awe)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(SOURCE_FILES awe/Report.cpp awe/IntegerIdentifier.cpp awe/Benchmark.cpp)
add_library(awe SHARED ${SOURCE_FILES})
