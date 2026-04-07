cmake_minimum_required(VERSION 3.25)

project(ModernCpp LANGUAGES CXX)

include(CTest)

if(BUILD_TESTING)
    find_package(GTest CONFIG QUIET)

    if(NOT GTest_FOUND)
        include(FetchContent)

        FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG v1.14.0
            GIT_SHALLOW TRUE
        )

        FetchContent_MakeAvailable(googletest)
    endif()
endif()

function(modern_cpp_configure_target target)
    target_compile_features(${target} PRIVATE cxx_std_20)

    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic)
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic)
    elseif(MSVC)
        target_compile_options(${target} PRIVATE /W4 /permissive-)
    endif()
endfunction()

add_executable(modern_cpp src/main.cpp)
modern_cpp_configure_target(modern_cpp)

add_subdirectory(chapters/01_control_flow_statements)
