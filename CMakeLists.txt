cmake_minimum_required(VERSION 3.12)
project(LSH C)

set(CMAKE_C_STANDARD 99)

add_executable(LSH main.c lib/utilities.c lib/utilities.h lib/LSH.c lib/LSH.h lib/Search_LSH.c lib/Search_LSH.h)