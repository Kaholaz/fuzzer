cmake_minimum_required(VERSION 3.5)

project(replace)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Wextra")

add_executable(replace main.c replace.c)
target_include_directories(replace INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(replace_fuzzer_test replace_fuzzer_test.c replace.c)
target_compile_options(replace_fuzzer_test PRIVATE -fsanitize=address,fuzzer)
target_link_options(replace_fuzzer_test PRIVATE -fsanitize=address,fuzzer)
target_include_directories(replace_fuzzer_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

