# Qt5 Calculator

A simple calculator application built with Qt5 (Core, Widgets, QML, Quick) and CMake using C++20.

## Requirements

- CMake ≥ 3.28

- Qt5 (Core, Widgets, Qml, Quick)
- C++20 compatible compiler

Windows:
- Visual Studio (MSVC) or MinGW GCC

Linux
- g++

## Build

Windows:
```
cmake -S . -B build -G "Visual Studio 17 2022"
```
```
cmake -S . -B build -G "MinGW Makefiles"
```

Linux:
```
cmake ..
make
```
