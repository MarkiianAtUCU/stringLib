cmake_minimum_required(VERSION 3.12)
set(CMAKE_C_STANDARD 99)

project(Lab_2)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ./bin/)

add_library(m_string SHARED m_string.c m_string.h)

add_executable(lib_test lib_test.c)
target_link_libraries(lib_test m_string)

add_executable(task_3 task_3.c)
target_link_libraries(lib_test m_string)
