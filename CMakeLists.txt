cmake_minimum_required(VERSION 3.15)
project(L2Z1)

set(CMAKE_CXX_STANDARD 20)


add_executable(L2Z1 main.cpp Board.cpp Board.h Engine.cpp Engine.h Interface.cpp Interface.h GameOver.cpp GameOver.h)