cmake_minimum_required(VERSION 3.28)

find_package(Qt5 COMPONENTS Core Widgets Qml Quick REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(SRC 
    src/main.cpp 
    src/Calculator.hpp 
    src/CalculatorWindow.hpp
    src/types.hpp
    resources/qml.qrc
)

add_executable(calculator ${SRC})

target_link_libraries(calculator PRIVATE Qt::Core Qt::Widgets Qt::Qml Qt::Quick)