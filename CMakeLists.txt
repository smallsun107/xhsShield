cmake_minimum_required(VERSION 3.19)
project(xhsShield)

set(CMAKE_CXX_STANDARD 14)

add_executable(xhsShield main.cpp xyAes.h xyAes.cpp xyMd5.h xyMd5.cpp xyXor.h xyXor.cpp base64.h base64.cpp)