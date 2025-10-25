cmake_minimum_required(VERSION 3.10)
project(NeuralVisualizer LANGUAGES C CXX) # need C compilier for GLAD and C++ for the rest

set(CMAKE_CXX_STANDARD 17) # Use C++17 standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)
include_directories(${CMAKE_SOURCE_DIR}/extern/glad/include)  # GLAD headers

# Source files
file(GLOB SOURCES src/*.cpp)
list(APPEND SOURCES ${CMAKE_SOURCE_DIR}/extern/glad/src/glad.c)  # add GLAD source

# Create executable
add_executable(neural_net ${SOURCES})

# Find libraries
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

# Link libraries
if(UNIX)
	# On Linux we often need -ldl for GL loader (glad) to resolve dynamic loader symbols
	find_library(DL_LIB dl)
	if(DL_LIB)
		target_link_libraries(neural_net PRIVATE glfw OpenGL::GL ${DL_LIB})
	else()
		target_link_libraries(neural_net PRIVATE glfw OpenGL::GL)
	endif()
else()
	target_link_libraries(neural_net PRIVATE glfw OpenGL::GL)
endif()
