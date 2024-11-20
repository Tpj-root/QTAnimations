cmake_minimum_required(VERSION 3.5)

# Set project name
project(AnimatedGifApp)

# Find required Qt5 packages
find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

# Enable automatic processing of MOC
set(CMAKE_AUTOMOC ON)

# Add source files
set(SOURCES main.cpp)

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link Qt5 libraries
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets)

