cmake_minimum_required(VERSION 3.10)

project(SyncTimeServer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
find_package(Boost 1.73 REQUIRED )
set(CMAKE_CXX_FLAGS "-lpthread")
add_executable(syncts SyncTimeserver.cpp)
