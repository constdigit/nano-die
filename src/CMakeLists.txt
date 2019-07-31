# Basic cmake setup
cmake_minimum_required(VERSION 3.10)
project(nano_die VERSION 0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

# Manage Dependencies
find_package(OpenCV REQUIRED)
find_package(Qt5 COMPONENTS Core Quick Widgets REQUIRED)
set(DEPENDENCIES ${OpenCV_LIBS} Qt5::Core Qt5::Widgets Qt5::Gui)

# Run Qt meta compiler
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Collect C++ source files
set(SOURCES main.cpp)

# Build binary
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${DEPENDENCIES})
