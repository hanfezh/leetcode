cmake_minimum_required(VERSION 3.0)

find_package(GTest CONFIG REQUIRED)

# file(GLOB TEST_SOURCES *.cpp)
set(TEST_SOURCES
    add_binary.cpp
    add_to_array_form.cpp
    balanced_binary_tree.cpp
    basic_calculator.cpp
    basic_calculator2.cpp
    basic_calculator3.cpp
    binary_tree_tilt.cpp
    champagne_tower.cpp
    climbing_stairs.cpp
    coin_change.cpp
    contains_duplicate.cpp
    count_complete_tree_nodes.cpp
    course_schedule.cpp
    custom_stack.cpp
    diameter_of_binary_tree.cpp
    eval_rpn.cpp
    fibonacci_number.cpp
    find_lhs.cpp
    find_the_difference.cpp
    find_the_duplicate_number.cpp
    find_the_peaks.cpp
    first_missing_positive.cpp
    flood_fill.cpp
    h_index.cpp
    implement_trie.cpp
    insert_interval.cpp
    kth_missing_positive_number.cpp
    kth_smallest_element.cpp
    k_closest_points.cpp
    linked_list_random_node.cpp
    longest_palindrome.cpp
    longest_substring.cpp
    length_of_last_word.cpp
    lowest_common_ancestor_bst.cpp
    majority_element.cpp
    maximum_gap.cpp
    maximum_profit.cpp
    maximum_swap.cpp
    merge_intervals.cpp
    middle_node.cpp
    minimum_arrow_shots.cpp
    min_add_to_make_valid.cpp
    min_stack.cpp
    next_permutation.cpp
    palindrome_number.cpp
    product_except_self.cpp
    range_sum_query.cpp
    recover_binary_search_tree.cpp
    remove_duplicates.cpp
    remove_element.cpp
    rotated_digits.cpp
    same_tree.cpp
    sample_stats.cpp
    search_insert_position.cpp
    sorted_squares.cpp
    sort_array.cpp
    sort_array_by_parity.cpp
    sort_array_by_parity2.cpp
    sort_characters_by_frequency.cpp
    sort_colors.cpp
    sort_list.cpp
    three_sum.cpp
    top_k_frequent_elements.cpp
    transpose_matrix.cpp
    two_sum.cpp
    update_matrix.cpp
    valid_parentheses.cpp
    valid_palindrome2.cpp
    walls_and_gates.cpp
    zigzag_conversion.cpp)

foreach(source_file ${TEST_SOURCES})
    # get_filename_component(source_file ${source_file} NAME)
    string(REPLACE ".cpp" "" test_name ${source_file})
    add_executable(${test_name} ${source_file})
    target_link_libraries(${test_name} PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
endforeach(source_file ${TEST_SOURCES})
