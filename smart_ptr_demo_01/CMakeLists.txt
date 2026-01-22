cmake_minimum_required(VERSION 3.10)
project(smart_ptr_demo)

set(CMAKE_CXX_STANDARD 17)

add_executable(smart_ptr_demo
    main.cpp
    class_a.cpp
    class_b.cpp
)
