cmake_minimum_required(VERSION 3.0)

find_package(GTest CONFIG REQUIRED)

# file(GLOB TEST_SOURCES *.cpp)
set(TEST_SOURCES
    add_to_array_form.cpp
    contains_duplicate.cpp
    find_the_difference.cpp
    first_missing_positive.cpp
    longest_substring.cpp
    length_of_last_word.cpp
    maximum_gap.cpp
    palindrome_number.cpp
    remove_element.cpp
    search_insert_position.cpp
    sorted_squares.cpp
    sort_list.cpp
    zigzag_conversion.cpp)

foreach(source_file ${TEST_SOURCES})
    # get_filename_component(source_file ${source_file} NAME)
    string(REPLACE ".cpp" "" test_name ${source_file})
    add_executable(${test_name} ${source_file})
    target_link_libraries(${test_name} PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
endforeach(source_file ${TEST_SOURCES})