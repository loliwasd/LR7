cmake_minimum_required(VERSION 3.22)
project(LR7)


add_library(String STATIC Tasks.cpp)

add_executable(AddressSan Tasks_ASAN.cpp)
target_compile_options(AddressSan PRIVATE -fsanitize=address)
target_link_options(AddressSan PRIVATE -fsanitize=address)



add_executable(ThreadSan Tasks_THREAD.cpp)
target_compile_options(ThreadSan PRIVATE -fsanitize=thread)
target_link_options(ThreadSan PRIVATE -fsanitize=thread)

enable_testing()