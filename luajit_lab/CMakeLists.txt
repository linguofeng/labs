cmake_minimum_required(VERSION 2.8)

# 头文件搜索目录
include_directories( include )
include_directories( /usr/local/include/luajit-2.0 )

# 编译标记
set(CMAKE_EXE_LINKER_FLAGS "-pagezero_size 10000 -image_base 100000000")

# 工程名
project( mainc )
# 生成可执行文件
add_executable( mainc src/main.c )
# 连接库
target_link_libraries( mainc luajit-5.1 )

# 工程2
project( maincpp )
add_executable( maincpp src/main.cpp )
target_link_libraries( maincpp luajit-5.1 )

# 工程3
project( maincpp2 )
add_executable( maincpp2 src/main2.cpp )
target_link_libraries( maincpp2 luajit-5.1 )

# 工程4
project( testcallback )
add_executable( testcallback src/testcallback.c )
target_link_libraries( testcallback luajit-5.1 )
