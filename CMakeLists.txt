cmake_minimum_required(VERSION 3.25)

project(ModernCpp LANGUAGES CXX)

add_executable(modern_cpp src/main.cpp)
target_compile_features(modern_cpp PRIVATE cxx_std_20)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(modern_cpp PRIVATE -Wall -Wextra -Wpedantic)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(modern_cpp PRIVATE -Wall -Wextra -Wpedantic)
elseif(MSVC)
    target_compile_options(modern_cpp PRIVATE /W4 /permissive-)
endif()