cmake_minimum_required(VERSION 3.10)

project("Exercises for \\\"The C programming language\\\" by Dennis Ritchie" VERSION 1.0)

configure_file("include/project_config.h.in" "include/project_config.h")
include_directories("${PROJECT_BINARY_DIR}/include")

#set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -std=c89") # sets c flags for all targets
#set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -v") # sets c flags for all targets

message(STATUS "C compiler: ${CMAKE_C_COMPILER}")
message(STATUS "C flags, debug/config: ${CMAKE_C_FLAGS_DEBUG}")
message(STATUS "C flags, release/config: ${CMAKE_C_FLAGS_RELEASE}")
message(STATUS "Linker flags, debug/config: ${CMAKE_EXE_LINKER_FLAGS_DEBUG}")
message(STATUS "Linker flags, release/config: ${CMAKE_EXE_LINKER_FLAGS_RELEASE}")

add_executable(1_07.out 1_07_print_value_EOF/main.c)
add_executable(1_08.out 1_08_count_blank_tab_newline/main.c)
add_executable(1_09.out 1_09_replace_shrink_blanks/main.c)
add_executable(1_10.out 1_10_replace_tab_backspace_backslash/main.c)
add_executable(1_12.out 1_12_print_word_per_line/main.c)
add_executable(1_13.out 1_13_histogram_by_word_length/main.c)
add_executable(1_14.out 1_14_histogram_by_chars/main.c)
add_executable(1_15.out 1_15_celsius_to_fahr/main.c)
add_executable(1_16.out 1_16_print_longest_input_line/main.c)
add_executable(1_17.out 1_17_print_lines_longer_than_80/main.c)
add_executable(1_18.out 1_18_remove_trailing_blanks_tabs/main.c)

add_executable(1_19.out 1_19_reverse_input/main.c)
#target_compile_options(1_19.out PRIVATE -v)
#target_link_options(1_19.out PRIVATE -v)

