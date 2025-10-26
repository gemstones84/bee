cmake_minimum_required(VERSION 3.27)
project(bee)

add_library(${PROJECT_NAME})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_sources(${PROJECT_NAME} PRIVATE src/bee.cpp)

if(NOT "${CMAKE_CXX_COMPILER_FRONTEND_VARIANT}" STREQUAL "MSVC")
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        -Wextra
        -fno-exceptions
        -fno-rtti
    )
endif()