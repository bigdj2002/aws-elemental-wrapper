cmake_minimum_required(VERSION 3.10)
project(aws_elemental)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include AWS SDK
find_package(AWSSDK REQUIRED COMPONENTS medialive)

# Include directories
include_directories(include)

add_subdirectory(app)