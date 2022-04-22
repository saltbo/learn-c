cmake_minimum_required(VERSION 3.20)
project(learn-c C)

# 设置
set(CMAKE_C_STANDARD 99)

# 编译源码生成目标
add_executable(learn-c main.c net/server.c net/server.h)