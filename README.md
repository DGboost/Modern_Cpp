# Modern_Cpp

Homebrew LLVM based C++ learning workspace for macOS and VS Code.

## Tooling choices

- Xcode Command Line Tools provide the macOS SDK and LLDB.
- Homebrew LLVM is the project compiler.
- CMake and Ninja handle configure and build.
- clangd and CodeLLDB provide editor intelligence and debugging in VS Code.

## Prerequisites

1. Install Xcode Command Line Tools.

```bash
xcode-select --install
```

2. Install Homebrew if it is not already installed.

3. Install the build tools.

```bash
brew install cmake ninja llvm
```

4. Verify the toolchain.

```bash
xcode-select -p
brew --version
cmake --version
ninja --version
$(brew --prefix llvm)/bin/clang++ --version
```

## First build

1. Open this folder in VS Code.
2. Install the recommended extensions from `.vscode/extensions.json`.
3. Configure the project.

```bash
cmake --preset brew-debug
```

4. Build the starter target.

```bash
cmake --build --preset brew-debug
```

5. Run it.

```bash
./build/brew-debug/modern_cpp
```

Expected output:

```text
Modern C++ environment ready. Sum = 10
```

## VS Code workflow

- Use the default build task `build (brew-debug)`.
- Use `run (brew-debug)` to build and execute from the integrated terminal.
- Start `Debug modern_cpp (brew-debug)` from Run and Debug to launch LLDB.

## Notes

- `CMakePresets.json` pins the compiler to `/opt/homebrew/opt/llvm/bin/clang++`.
- If your Homebrew prefix is different, update `CMakePresets.json` to match `brew --prefix llvm`.
- `.clangd` points clangd at `build/brew-debug`, so configure once before expecting full completion and navigation.
