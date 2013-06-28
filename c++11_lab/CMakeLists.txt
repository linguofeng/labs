cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")
project(Test)
add_executable(Test src/main.cpp)
