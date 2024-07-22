cmake_minimum_required(VERSION 3.5.0)
project(Queue VERSION 0.1.0 LANGUAGES C CXX)

add_executable(Queue main.cpp)
add_subdirectory(./include)
target_include_directories(Queue PUBLIC ./include)
# target_link_libraries(Queue 
#         PUBLIC 
#         queue
#         )
add_compile_options("-Wall")