cmake_minimum_required(VERSION 3.10)
project(FdbExample)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include FoundationDB headers
include_directories(/usr/include/foundationdb)

set(FDB_LIB /usr/lib/libfdb_c.so)

# Ensure that the necessary libraries (libm, libpthread, librt) are linked
find_library(MATH_LIB m)
find_library(PTHREAD_LIB pthread)
find_library(RT_LIB rt)

# Create the executable from the source files
add_executable(FdbExample main.cpp)

# Link the executable with the FoundationDB client library and the required dependencies
target_link_libraries(FdbExample ${FDB_LIB} ${MATH_LIB} ${PTHREAD_LIB} ${RT_LIB})
