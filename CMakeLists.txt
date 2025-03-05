cmake_minimum_required(VERSION 3.30)
project(Data_Structures)

set(CMAKE_CXX_STANDARD 23)

add_executable(Data_Structures main.cpp
        String.cpp
        String.h
        vector.tpp
        vector.h
        linked_list.cpp
        linked_list.h
        stack.tpp
        stack.h
)
