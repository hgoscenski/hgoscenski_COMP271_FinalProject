cmake_minimum_required(VERSION 3.6)
project(hgoscenski_COMP271_FinalProject)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Station.cpp Station.h Line.cpp Line.h)
add_executable(hgoscenski_COMP271_FinalProject ${SOURCE_FILES} Station.cpp Station.h Line.cpp Line.h)