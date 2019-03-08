cmake_minimum_required (VERSION 2.8.11)

project (mydebug_template)

# creates the executable, which will be build out of the source files

add_executable(mydebug_template main-debug.cpp basic.tpp IR.tpp UIR.tpp BR.tpp DAG.tpp DAG-cmp.tpp DAG-cover.tpp DAG-sum.tpp DAG-make.tpp)


# compiler flags

add_definitions(-std=c++14 -Wall -Wextra -Wpedantic)

