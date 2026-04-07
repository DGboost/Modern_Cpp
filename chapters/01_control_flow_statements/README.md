# 01. Control Flow & Statements

This chapter isolates small, testable examples for core statement-level control flow.

## Topics

- `if-else` through score classification.
- `switch` through command selection.
- `goto` through a loop-with-label example.

## Layout

- `include/control_flow_statements/control_flow_examples.hpp`: public declarations.
- `src/control_flow_examples.cpp`: implementation of the chapter examples.
- `src/main.cpp`: small demo program for manual runs.
- `tests/control_flow_examples_test.cpp`: GoogleTest-based checks for the chapter functions.

## Build and run

```bash
cmake --build --preset brew-debug --target chapter01_control_flow_demo
./build/brew-debug/chapters/01_control_flow_statements/chapter01_control_flow_demo
```

## Run tests

```bash
cmake --build --preset brew-debug --target chapter01_control_flow_tests
ctest --test-dir build/brew-debug --output-on-failure -R chapter01_control_flow_tests
```

You can also run only one GoogleTest case directly:

```bash
./build/brew-debug/chapters/01_control_flow_statements/chapter01_control_flow_tests \
	--gtest_filter=DescribeCommandTest.*
```

## Notes

- GoogleTest is resolved by CMake. If it is not already installed on the machine, configure will fetch it automatically.
- The `goto` example is included for learning purposes only. In regular application code, structured loops are usually a better choice.
- Keep `main.cpp` thin. Add new experiments as functions first, then call them from the demo program.
