#cmake_minimum_required(VERSION 3.16)
cmake_minimum_required(VERSION 2.8)
project(cleanLogo)
set(CMAKE_CXX_STANDARD 17)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable(cleanLogo main.cpp)
target_link_libraries( cleanLogo ${OpenCV_LIBS} )

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()
if(LINUX)
    message(STATUS ">>> Linux")
    target_link_libraries(cleanLogo stdc++fs)
#    export CC=`which gcc`
#    export LD_LIBRARY_PATH=/usr/local/lib:/usr/lib:/usr/local/lib64:/usr/lib64
else()
    message(STATUS ">>> Not Linux")
    # stuff that should happen not on Linux
endif()

