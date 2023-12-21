cmake_minimum_required(VERSION 3.27)
project(TicTacToe VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)

include(CTest)
enable_testing()

add_executable(TicTacToe main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
