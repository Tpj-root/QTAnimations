cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(AnimatedGifApp VERSION 1.0)

# Find Qt5 package (make sure Qt5 is installed on your system)
find_package(Qt5 REQUIRED COMPONENTS Widgets)

# Include the directories where Qt5 headers are located
include_directories(${Qt5Widgets_INCLUDE_DIRS})

# Add the source file
add_executable(AnimatedGifApp main.cpp)

# Link Qt5 Widgets libraries
target_link_libraries(AnimatedGifApp Qt5::Widgets)

# Set C++ standard to C++11 (or higher, depending on your Qt version)
set_target_properties(AnimatedGifApp PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
)

# Optionally set the output directory for the binary
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


