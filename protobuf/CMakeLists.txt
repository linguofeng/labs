cmake_minimum_required(VERSION 2.8)
project(Test)
set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")

find_package(Protobuf REQUIRED) 
include_directories(${PROTOBUF_INCLUDE_DIRS})
 
include_directories(${CMAKE_CURRENT_BINARY_DIR})
PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS proto/Person.proto)
add_executable(Test src/main.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(Test ${PROTOBUF_LIBRARY})
