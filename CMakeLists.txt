cmake_minimum_required(VERSION 3.2)
project(ava VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -DNDEBUG")

include(CTest)
enable_testing()

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)