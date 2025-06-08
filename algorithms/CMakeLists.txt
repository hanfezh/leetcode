cmake_minimum_required(VERSION 3.0)

find_package(GTest CONFIG REQUIRED)

# file(GLOB TEST_SOURCES *.cpp)
set(TEST_SOURCES
    add_binary.cpp
    add_to_array_form.cpp
    armstrong_number.cpp
    balanced_binary_tree.cpp
    balance_bst.cpp
    basic_calculator.cpp
    basic_calculator2.cpp
    basic_calculator3.cpp
    binary_tree_tilt.cpp
    champagne_tower.cpp
    clear_digits.cpp
    climbing_stairs.cpp
    cloest_meeting_node.cpp
    coin_change.cpp
    contains_duplicate.cpp
    contains_pattern.cpp
    count_complete_tree_nodes.cpp
    count_partitions.cpp
    count_subarrays.cpp
    course_schedule.cpp
    custom_stack.cpp
    diameter_of_binary_tree.cpp
    eval_rpn.cpp
    exam_room.cpp
    fibonacci_number.cpp
    find_all_people.cpp
    find_judge.cpp
    find_lhs.cpp
    find_the_difference.cpp
    find_the_duplicate_number.cpp
    find_the_peaks.cpp
    first_missing_positive.cpp
    first_palindrome.cpp
    flood_fill.cpp
    highest_peak.cpp
    h_index.cpp
    implement_trie.cpp
    insert_interval.cpp
    kth_missing_positive_number.cpp
    kth_smallest_element.cpp
    k_closest_points.cpp
    largest_divisible_subset.cpp
    lexicographical_numbers.cpp
    linked_list_random_node.cpp
    longest_palindrome.cpp
    longest_substring.cpp
    length_of_last_word.cpp
    lowest_common_ancestor_bst.cpp
    majority_element.cpp
    maximum_gap.cpp
    maximum_odd_number.cpp
    maximum_profit.cpp
    maximum_swap.cpp
    max_chunks_to_sorted.cpp
    max_points.cpp
    max_stack.cpp
    median_sorted_arrays.cpp
    merge_intervals.cpp
    merge_sorted_array.cpp
    middle_node.cpp
    minimum_arrow_shots.cpp
    minimum_recolors.cpp
    min_add_to_make_valid.cpp
    min_max_game.cpp
    min_operations.cpp
    min_stack.cpp
    missing_number.cpp
    missing_ranges.cpp
    next_permutation.cpp
    number_containers.cpp
    palindrome_number.cpp
    permutation_in_string.cpp
    prefix_common_array.cpp
    product_except_self.cpp
    range_sum_query.cpp
    recover_binary_search_tree.cpp
    remove_duplicates.cpp
    remove_occurrences.cpp
    remove_element.cpp
    rotated_digits.cpp
    same_tree.cpp
    sample_stats.cpp
    search_insert_position.cpp
    shifting_letters2.cpp
    smaller_numbers.cpp
    sorted_squares.cpp
    sort_array.cpp
    sort_array_by_parity.cpp
    sort_array_by_parity2.cpp
    sort_characters_by_frequency.cpp
    sort_colors.cpp
    sort_list.cpp
    special_array1.cpp
    stable_mountains.cpp
    third_maximum_number.cpp
    three_sum.cpp
    tic_tac_toe.cpp
    time_map.cpp
    top_k_frequent_elements.cpp
    transpose_matrix.cpp
    triangle_type.cpp
    tuple_same_product.cpp
    two_sum.cpp
    update_matrix.cpp
    unique_occurrences.cpp
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
