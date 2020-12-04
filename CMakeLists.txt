cmake_minimum_required(VERSION 3.16)
project(cleanLogo)
set(CMAKE_CXX_STANDARD 17)


# expected behaviour
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable(cleanLogo main.cpp)
target_link_libraries( cleanLogo ${OpenCV_LIBS} )

target_link_libraries(cleanLogo stdc++fs)
