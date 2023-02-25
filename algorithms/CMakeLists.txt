cmake_minimum_required(VERSION 3.0)

find_package(GTest CONFIG REQUIRED)

# file(GLOB TEST_SOURCES *.cpp)
set(TEST_SOURCES
    add_binary.cpp
    add_to_array_form.cpp
    balanced_binary_tree.cpp
    binary_tree_tilt.cpp
    climbing_stairs.cpp
    contains_duplicate.cpp
    diameter_of_binary_tree.cpp
    eval_rpn.cpp
    find_lhs.cpp
    find_the_difference.cpp
    first_missing_positive.cpp
    flood_fill.cpp
    insert_interval.cpp
    k_closest_points.cpp
    longest_palindrome.cpp
    longest_substring.cpp
    length_of_last_word.cpp
    lowest_common_ancestor_bst.cpp
    majority_element.cpp
    maximum_gap.cpp
    maximum_profit.cpp
    middle_node.cpp
    min_stack.cpp
    palindrome_number.cpp
    product_except_self.cpp
    recover_binary_search_tree.cpp
    remove_element.cpp
    same_tree.cpp
    search_insert_position.cpp
    sorted_squares.cpp
    sort_colors.cpp
    sort_list.cpp
    two_sum.cpp
    valid_parentheses.cpp
    zigzag_conversion.cpp)

foreach(source_file ${TEST_SOURCES})
    # get_filename_component(source_file ${source_file} NAME)
    string(REPLACE ".cpp" "" test_name ${source_file})
    add_executable(${test_name} ${source_file})
    target_link_libraries(${test_name} PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
endforeach(source_file ${TEST_SOURCES})
