cmake_minimum_required(VERSION 3.18.4)

project(matrices VERSION 0.1.0 LANGUAGES CXX)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# headers
set( Headers
    matrix.h
)

# source
set( Sources
    matrix.cpp
)

# tests
set( TestSources
)

add_executable(${PROJECT_NAME} matrix_main.cpp ${Headers} ${Sources})