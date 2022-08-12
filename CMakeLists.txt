cmake_minimum_required(VERSION 3.23)
project(MyStdLib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_executable(UniquePtr unique_ptr.cxx)
# add_executable(MyUnorderedMap unordered_map.cxx)
add_executable(Vector vector.cxx)
add_executable(Utils utils.cxx)
add_executable(SharedPtr shared_ptr.cxx)

