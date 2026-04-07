set(chapter01_output_dir "${CMAKE_BINARY_DIR}/chapters/01_control_flow_statements")

include(GoogleTest)

add_library(chapter01_control_flow
    src/control_flow_examples.cpp
)

target_include_directories(chapter01_control_flow
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

modern_cpp_configure_target(chapter01_control_flow)

add_executable(chapter01_control_flow_demo
    src/main.cpp
)

target_link_libraries(chapter01_control_flow_demo
    PRIVATE
        chapter01_control_flow
)

set_target_properties(chapter01_control_flow_demo PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${chapter01_output_dir}
)

modern_cpp_configure_target(chapter01_control_flow_demo)

if(BUILD_TESTING)
    add_executable(chapter01_control_flow_tests
        tests/control_flow_examples_test.cpp
    )

    target_link_libraries(chapter01_control_flow_tests
        PRIVATE
            chapter01_control_flow
            GTest::gtest_main
    )

    set_target_properties(chapter01_control_flow_tests PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${chapter01_output_dir}
    )

    modern_cpp_configure_target(chapter01_control_flow_tests)

    gtest_discover_tests(
        chapter01_control_flow_tests
        TEST_PREFIX "chapter01_control_flow_tests."
        WORKING_DIRECTORY ${chapter01_output_dir}
    )
endif()
