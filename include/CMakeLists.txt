cmake_minimum_required(VERSION 3.5.0)


add_library(queue queue.cpp)
target_include_directories(queue PUBLIC ./)