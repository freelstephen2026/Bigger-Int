cmake_minimum_required(VERSION 3.10)

project(mylibrary VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the source files for the library
set(SOURCES
    src/main.cpp
)

# Create the shared library target
add_library(this SHARED ${SOURCES})

# Set the library version
set_target_properties(this PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/cmake)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/cmake)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/cmake)

# Specify the library installation directory
install(TARGETS this LIBRARY DESTINATION ${CMAKE_BINARY_DIR}/build/lib)


add_executable(test ${CMAKE_BINARY_DIR}/src/test.cpp)
set_target_properties(test PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/bin
)
target_link_libraries(test this)
# Specify the header file installation directory
file(COPY include/ DESTINATION ${CMAKE_BINARY_DIR}/build/include)
#OLD: install(DIRECTORY include/ DESTINATION ${CMAKE_BINARY_DIR}build/include)
