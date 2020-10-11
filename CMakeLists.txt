# cmake_minimum_required(VERSION <specify CMake version here>)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_executable(test main.cpp method.cpp head.h methodName.h singleList.h singleList.cpp common.h dList.h liStack.h liStack.cpp seqStack.cpp seqStack.h)