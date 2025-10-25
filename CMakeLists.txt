# cmake configuration file to build project
# to build: mkdir build, cd bild, cmake .., make
cmake_minimum_required(VERSION 3.10)
project(NeuralVisualizer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directory
include_directories(include)

# Gather all cpp files automatically
file(GLOB SOURCES src/*.cpp)

add_executable(neural_net ${SOURCES})
