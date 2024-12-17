cmake_minimum_required(VERSION 3.10)
project(ClassScheduling)

# Set C++ version to C++11 or later
set(CMAKE_CXX_STANDARD 11)

# Specify Flow source directory
set(FLOW_DIR "foundationdb/flow")

# Include Flow headers and compile
include_directories(${FLOW_DIR}/include)

# Add your source files
add_executable(ClassScheduling main.cpp)

# Link Flow runtime libraries
target_link_libraries(ClassScheduling ${FLOW_DIR}/libflow.a)