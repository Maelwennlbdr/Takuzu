cmake_minimum_required(VERSION 3.21)
project(Takusu C)

set(CMAKE_C_STANDARD 99)

add_executable(Takusu main.c menu.c menu.h basicFunction.c basicFunction.h verifCoup.c verifCoup.h gameMatrix.c gameMatrix.h resolveGrid.c resolveGrid.h)
