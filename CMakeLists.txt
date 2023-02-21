cmake_minimum_required(VERSION 3.10)

project(mylibrary VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(LIB_SRC
    src/int128.cpp
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/CMakeFiles)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/CMakeFiles)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/CMakeFiles)

add_library(int128 SHARED ${LIB_SRC})
target_include_directories(int128 PRIVATE include)

install(TARGETS int128 LIBRARY DESTINATION ${CMAKE_BINARY_DIR}/build/lib)

add_executable(test ${CMAKE_BINARY_DIR}/src/test.cpp)
set_target_properties(test PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/bin
)
target_include_directories(test PRIVATE include)
target_link_libraries(test int128)