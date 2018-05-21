cmake_minimum_required(VERSION 3.7)
project(codetest)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES leetcode/eightqueen.cpp leetcode/mergeklists.cc)
add_executable(codetest ${SOURCE_FILES})