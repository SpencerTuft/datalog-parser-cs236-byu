cmake_minimum_required(VERSION 3.8)
project(datalog-parser-cs236-byu)

include_directories(include)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Werror -g")

file(GLOB SOURCES "./src/*")
add_executable(datalog-parser-cs236-byu ${SOURCES})