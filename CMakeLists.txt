cmake_minimum_required(VERSION 3.27)
project(bee)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BEE_BUILD_LIBRARY "Build static library" ON)

add_subdirectory(bee)