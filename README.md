# LeetCode

## How to build C++?

1. Install vcpkg

```
git clone https://github.com/microsoft/vcpkg
./vcpkg/bootstrap-vcpkg.sh
```

2. Install deps gtest

```
./vcpkg/vcpkg install gtest
```

3. Build with cmake

```
cmake -B build -S . "-DCMAKE_TOOLCHAIN_FILE=$(pwd)/vcpkg/scripts/buildsystems/vcpkg.cmake"
cmake --build build
```

## Problems & Solutions

| No. | Title | Difficulty | Solutions | Topics |
| - | ----- | ---------- | --------- | ---- |
| 1 | [Two Sum](https://leetcode.com/problems/two-sum) | Easy | [C++](./algorithms/two_sum.cpp) [Go](./algorithms/two_sum.go) | `Array` `Hash Table` |
| 2	| [Add Two Numbers](https://leetcode.com/problems/add-two-numbers) | Medium | [C++](./algorithms/add_two_numbers.cpp) [Python](./algorithms/add_two_numbers.py) | `Linked List` |
| 3	| [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters) | Medium | [C++](./algorithms/longest_substring.cpp) [Python](./algorithms/longest_substring.py) | `String` `Sliding Window` `Hash Table` |
| 4 | [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays) | Hard | [C++](./algorithms/median_sorted_arrays.cpp) [Go](./algorithms/median_sorted_arrays.go) | `Binary Search` |
| 5 | [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring) | Medium | [C](./algorithms/longest_palindromic_substring.c) [C++](./algorithms/longest_palindromic_substring.cpp)| `String` `Dynamic Programming` |
| 6 | [ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion) | Medium | [C](./algorithms/zigzag_conversion.c) | `String` |
| 7 | [Reverse Integer](https://leetcode.com/problems/reverse-integer) | Easy | [C++](./algorithms/reverse_integer.cpp) [Python](./algorithms/reverse_integer.py) | `Math` |
| 8 | [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi) | Medium | [C++](./algorithms/atoi.cpp) [Python](./algorithms/atoi.py) | `Math` |
| 9 | [Palindrome Number](https://leetcode.com/problems/palindrome-number) | Easy | [C++](./algorithms/palindrome_number.cpp) [Python](./algorithms/palindrome_number.py) | `Math` |
| 10 | [Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching) | Hard | [C++](./algorithms/regular_expression_matching.cpp) |
| 11 | [Container With Most Water](https://leetcode.com/problems/container-with-most-water) | Medium | [C++](./algorithms/container_with_most_water.cpp) |
| 12 | [Integer to Roman](https://leetcode.com/problems/integer-to-roman) | Medium | [C++](./algorithms/integer_to_roman.cpp) |
| 13 | [Roman to Integer](https://leetcode.com/problems/roman-to-integer) | Easy | [C++](./algorithms/roman_to_integer.cpp) | `Math` |
| 14 | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix) | Easy | [C++](./algorithms/longest_common_prefix.cpp) | `String` |
| 15 | [3Sum](https://leetcode.com/problems/3sum) | Medium | [C](./algorithms/three_sum.c) [C++](./algorithms/three_sum.cpp) | `Array` `Two Pointers` `Sorting` |
| 16 | [3Sum Closest](https://leetcode.com/problems/3sum-closest) | Medium | [C++](./algorithms/three_sum_closest.cpp) |
| 17 | [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) | Medium | [C++](./algorithms/letter_combinations.cpp) |
| 18 | [4Sum](https://leetcode.com/problems/4sum) | Medium | [C++](./algorithms/four_sum.cpp) |
| 19 | [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list) | Medium | [C++](./algorithms/remove_nth_from_end.cpp) | `Two Pointers` |
| 20 | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses) | Easy | [C++](./algorithms/valid_parentheses.cpp) [Python](./algorithms/valid_parentheses.py) | `String` `Stack` |
| 21 | [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists) | Easy | [C](./algorithms/merge_two_lists.c) [Python3](./algorithms/merge_two_lists.py) | `Linked List` |
| 22 | [Generate Parentheses](https://leetcode.com/problems/generate-parentheses) | Medium | [C++](./algorithms/generate_parentheses.cpp) |
| 23 | [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists) | Hard | [C++](./algorithms/merge_k_sorted_lists.cpp) | `Sorting` `Priority Queue`|
| 24 | [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs) | Medium | [C++](./algorithms/swap_nodes_in_pairs.cpp) | `Linked List` |
| 25 | [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group) | Hard | [C++](./algorithms/reverse_nodes_in_k_group.cpp) [Python3](./algorithms/reverse_nodes_in_k_group.py) | `Linked List` `Recursion` |
| 26 | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array) | Easy | [C++](./algorithms/remove_duplicates.cpp) [Python](./algorithms/remove_duplicates.py) | `Array` `Two Pointers` |
| 27 | [Remove Element](https://leetcode.com/problems/remove-element) | Easy | [Python](./algorithms/remove_element.py) | `Array` `Two Pointers` |
| 28 | [Implement strStr()](https://leetcode.com/problems/implement-strstr) | Easy | [C++](./algorithms/str_str.cpp) | `String` `KMP` |
| 29 | [Divide Two Integers](https://leetcode.com/problems/divide-two-integers) | Medium | [C++](./algorithms/divide_two_integers.cpp) |
| 30 | [Substring with Concatenation of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words) | Hard | [C++](./algorithms/substring_with_concatenation_words.cpp) | `Hash Table` |
| 31 | [Next Permutation](https://leetcode.com/problems/next-permutation) | Medium | [C++](./algorithms/next_permutation.cpp) | `Array` |
| 32 | [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses) | Hard | [C++](./algorithms/longest_valid_parentheses.cpp) | `Stack` |
| 33 | [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array) | Medium | [C++](./algorithms/search_in_rotated_sorted_array.cpp) [Go](./algorithms/search_in_rotated_sorted_array.go) | `Array` `Binary Search` |
| 34 | [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array) | Medium | [C++](./algorithms/position_in_sorted_array.cpp) |
| 35 | [Search Insert Position](https://leetcode.com/problems/search-insert-position) | Easy | [C++](./algorithms/search_insert_position.cpp) | `Array` `Binary Search` |
| 36 | [Valid Sudoku](https://leetcode.com/problems/valid-sudoku) | Medium | [C++](./algorithms/valid_sudoku.cpp) | `Hash Table` |
| 38 | [Count and Say](https://leetcode.com/problems/count-and-say) | Easy | [C++](./algorithms/count_and_say.cpp) | `String` |
| 39 | [Combination Sum](https://leetcode.com/problems/combination-sum) | Medium | [C++](./algorithms/combination_sum.cpp) |
| 40 | [Combination Sum II](https://leetcode.com/problems/combination-sum-ii) | Medium | [C++](./algorithms/combination_sum2.cpp) |
| 41 | [First Missing Positive](https://leetcode.com/problems/first-missing-positive) | Hard | [C++](./algorithms/first_missing_positive.cpp) | `Array` `Hash Table` |
| 42 | [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water) | Hard | [C++](./algorithms/trapping_rain_water.cpp) | `Dynamic Programming` |
| 43 | [Multiply Strings](https://leetcode.com/problems/multiply-strings) | Medium | [C++](./algorithms/multiply_strings.cpp) |
| 44 | [Wildcard Matching](https://leetcode.com/problems/wildcard-matching) | Hard | [C++](./algorithms/wildcard_matching.cpp) | `Backtracking` |
| 46 | [Permutations](https://leetcode.com/problems/permutations) | Medium | [C++](./algorithms/permutations.cpp) | `DFS` |
| 47 | [Permutations II](https://leetcode.com/problems/permutations-ii) | Medium | [C++](./algorithms/permutations2.cpp) | `DFS` |
| 48 | [Rotate Image](https://leetcode.com/problems/rotate-image) | Medium | [C++](./algorithms/rotate_image.cpp) | `Array` |
| 49 | [Group Anagrams](https://leetcode.com/problems/group-anagrams) | Medium | [C++](./algorithms/group_anagrams.cpp) | `String` |
| 50 | [Pow(x, n)](https://leetcode.com/problems/powx-n) | Medium | [C++](./algorithms/pow.cpp) | `Binary Search` |
| 53 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray) | Medium | [C++](./algorithms/maximum_subarray.cpp) | `Array` |
| 54 | [Spiral Matrix](https://leetcode.com/problems/spiral-matrix) | Medium | [C++](./algorithms/spiral_matrix.cpp) | `Array` |
| 55 | [Jump Game](https://leetcode.com/problems/jump-game) | Medium | [C++](./algorithms/jump_game.cpp) | `Dynamic Programming` |
| 56 | [Merge Intervals](https://leetcode.com/problems/merge-intervals) | Medium | [C++](./algorithms/merge_intervals.cpp) | `Array` `Sorting` |
| 57 | [Insert Interval](https://leetcode.com/problems/insert-interval) | Medium | [C++](./algorithms/insert_interval.cpp) | `Array` |
| 58 | [Length of Last Word](https://leetcode.com/problems/length-of-last-word) | Easy | [C++](./algorithms/length_of_last_word.cpp) | `String` |
| 59 | [Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii) | Medium | [C++](./algorithms/spiral_matrix2.cpp) | `Array` |
| 60 | [Permutation Sequence](https://leetcode.com/problems/permutation-sequence) | Medium | [C++](./algorithms/permutation_sequence.cpp) | |
| 61 | [Rotate List](https://leetcode.com/problems/rotate-list/) | Medium | [C++](./algorithms/rotate_list.cpp) [Python3](./algorithms/rotate_list.py) | `Linked List` |
| 62 | [Unique Paths](https://leetcode.com/problems/unique-paths) | Medium | [C](./algorithms/unique_paths.c) [C++](./algorithms/unique_paths.cpp) | `Dynamic Programming` |
| 63 | [Unique Paths II](https://leetcode.com/problems/unique-paths-ii) | Medium | [C++](./algorithms/unique_paths2.cpp) | `Dynamic Programming` |
| 64 | [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum) | Medium | [C++](./algorithms/minimum_path_sum.cpp) | `Dynamic Programming` |
| 66 | [Plus One](https://leetcode.com/problems/plus-one) | Easy | [C++](./algorithms/plus_one.cpp) | `Array` |
| 67 | [Add Binary](https://leetcode.com/problems/add-binary/) | Easy | [C++](./algorithms/add_binary.cpp) | `String` `Bit Manipulation` |
| 69 | [Sqrt(x)](https://leetcode.com/problems/sqrtx) | Easy | [C++](./algorithms/sqrt.cpp) | `Binary search` |
| 70 | [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) | Easy | [C++](./algorithms/climbing_stairs.cpp) | `Dynamic Programming` |
| 71 | [Simplify Path](https://leetcode.com/problems/simplify-path) | Medium | [C++](./algorithms/simplify_path.cpp) | |
| 72 | [Edit Distance](https://leetcode.com/problems/edit-distance) | Hard | [C++](./algorithms/edit_distance.cpp) | `Dynamic Programming` |
| 73 | [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes) | Medium | [C++](./algorithms/set_matrix_zeroes.cpp) | `Array` |
| 74 | [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix) | Medium | [C++](./algorithms/search_2d_matrix.cpp) | `Binary Search` |
| 75 | [Sort Colors](https://leetcode.com/problems/sort-colors) | Medium | [C++](./algorithms/sort_colors.cpp) | `Array` `Two Pointers` |
| 76 | [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) | Hard | [C++](./algorithms/min_window.cpp) | `Hash Table` `Sliding Window` |
| 77 | [Combinations](https://leetcode.com/problems/combinations) | Medium | [C++](./algorithms/combinations.cpp) |
| 78 | [Subsets](https://leetcode.com/problems/subsets) | Medium | [C++](./algorithms/subsets.cpp) |
| 79 | [Word Search](https://leetcode.com/problems/word-search) | Medium | [C++](./algorithms/word_search.cpp) | `Backtracking` |
| 80 | [Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii) | Medium | [C++](./algorithms/remove_duplicates_from_array2.cpp) | `Array` |
| 81 | [Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii) | Medium | [C++](./algorithms/search_in_rotated_sorted_array2.cpp) |
| 82 | [Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii) | Medium | [C++](./algorithms/remove_duplicates_from_list2.cpp) [Python3](./algorithms/remove_duplicates_from_list2.py) | `Linked List` `Two Pointers` |
| 83 | [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list) | Easy | [C++](./algorithms/remove_duplicates_from_list.cpp) |
| 86 | [Partition List](https://leetcode.com/problems/partition-list) | Medium | [C++](./algorithms/partition_list.cpp) | |
| 88 | [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/) | Easy | [C++](./algorithms/merge_sorted_array.cpp) | `Two Pointers` |
| 89 | [Gray Code](https://leetcode.com/problems/gray-code) | Medium | [C++](./algorithms/gray_code.cpp) | `Bit Manipulation` |
| 90 | [Subsets II](https://leetcode.com/problems/subsets-ii) | Medium | [C++](./algorithms/subsets2.cpp) |
| 91 | [Decode Ways](https://leetcode.com/problems/decode-ways) | Medium | [C++](./algorithms/decode_ways.cpp) | `Dynamic Programming` |
| 92 | [Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii) | Medium | [C++](./algorithms/reverse_linked_list2.cpp) | `Linked List` |
| 93 | [Restore IP Addresses](https://leetcode.com/problems/restore-ip-addresses) | Medium | [C++](./algorithms/restore_ip_addresses.cpp) | `DFS` |
| 94 | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal) | Medium | [C++](./algorithms/binary_tree_inorder_traversal.cpp) [Go](./algorithms/binary_tree_inorder_traversal.go) | `Tree` `Stack` |
| 95 | [Unique Binary Search Trees II](https://leetcode.com/problems/unique-binary-search-trees-ii) | Medium | [C++](./algorithms/unique_binary_search_trees2.cpp) | `Tree` |
| 96 | [Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees) | Medium | [C++](./algorithms/unique_binary_search_trees.cpp) | `Dynamic Programming` |
| 98 | [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree) | Medium | [C++](./algorithms/validate_binary_search_tree.cpp) | `DFS` `Inorder Traversal`|
| 99 | [Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree/) | Medium | [C++](./algorithms/recover_binary_search_tree.cpp) | `DFS` `Inorder Traversal`|
| 100 | [Same Tree](https://leetcode.com/problems/same-tree) | Easy | [C++](./algorithms/same_tree.cpp) | `Tree` `DFS` `BFS` |
| 101 | [Symmtric Tree](https://leetcode.com/problems/symmetric-tree) | Easy | [C++](./algorithms/symmetric_tree.cpp) | `Tree` `DFS` `BFS` |
| 102 | [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal) | Medium | [C++](./algorithms/binary_tree_level_order_traversal.cpp) | `Tree` `BFS` `DFS` |
| 103 | [Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal) | Medium | [C++](./algorithms/binary_tree_zigzag_order_traversal.cpp) | `Tree` |
| 104 | [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree) | Easy | [C++](./algorithms/maximum_depth.cpp) | `Tree` `DFS` |
| 105 | [Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal) | Medium | [C++](./algorithms/construct_binary_tree_from_preorder.cpp) | `Tree` `DFS` |
| 106 | [Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal) | Medium | [C++](./algorithms/construct_binary_tree_from_postorder.cpp) | `Tree` `DFS` |
| 107 | [Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii) | Easy | [C++](./algorithms/binary_tree_level_order_traversal2.cpp) | `Tree` |
| 108 | [Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree) | Easy | [C++](./algorithms/convert_sorted_array_to_bst.cpp) | `Tree` |
| 109 | [Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree) | Medium | [C++](./algorithms/convert_sorted_list_to_bst.cpp) | `Tree` |
| 110 | [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree) | Easy | [C++](./algorithms/balanced_binary_tree.cpp) | `Tree` `DFS` |
| 111 | [Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree) | Easy | [C++](./algorithms/minimum_depth_of_binary_tree.cpp) | `Tree` |
| 112 | [Path Sum](https://leetcode.com/problems/path-sum) | Easy | [C++](./algorithms/path_sum.cpp) [Python](./algorithms/path_sum.py) | `Tree` `DFS` |
| 113 | [Path Sum II](https://leetcode.com/problems/path-sum-ii) | Medium | [Python](./algorithms/path_sum2.py) |
| 114 | [Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list) | Medium | [C++](./algorithms/flatten_binary_tree_to_linked_list.cpp) | `Tree` |
| 115 | [Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences) | Hard | [C++](./algorithms/distinct_subsequences.cpp) | `Dynamic Programming` |
| 116 | [Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node) | Medium | [C++](./algorithms/populating_next_right_pointers.cpp) | `Tree` `DFS` |
| 117 | [Populating Next Right Pointers in Each Node II](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii) | Medium | [C++](./algorithms/populating_next_right_pointers2.cpp) | `Tree` `BFS` `DFS` |
| 118 | [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle) | Easy | [C++](./algorithms/pascal_triangle.cpp) | `Array` |
| 119 | [Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii) | Easy | [C++](./algorithms/pascal_triangle2.cpp) | `Array` |
| 120 | [Triangle](https://leetcode.com/problems/triangle) | Medium | [C++](./algorithms/triangle.cpp) | `Dynamic Programming` |
| 121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock) | Easy | [C++](./algorithms/maximum_profit.cpp) | `Array` |
| 122 | [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii) | Easy | [C++](./algorithms/maximum_profit2.cpp) | `Array` |
| 123 | [Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii) | Hard | [C++](./algorithms/maximum_profit3.cpp) |
| 124 | [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum) | Hard | [C++](./algorithms/binary_tree_maximum_path_sum.cpp) | `Tree` `DFS` |
| 125 | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome) | Easy | [C++](./algorithms/valid_palindrome.cpp) | `String` `Two Pointers` |
| 126 | [Word Ladder II](https://leetcode.com/problems/word-ladder-ii) | Hard | [C++](./algorithms/word_ladder2.cpp) | `BFS` |
| 127 | [Word Ladder](https://leetcode.com/problems/word-ladder) | Medium | [C++](./algorithms/word_ladder.cpp) | `BFS` |
| 128 | [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence) | Medium | [C++](./algorithms/longest_consecutive_sequence.cpp) | `Array` |
| 129 | [Sum Root to Leaf Numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers) | Medium | [C++](./algorithms/sum_root_to_leaf_numbers.cpp) | `DFS` |
| 130 | [Surrounded Regions](https://leetcode.com/problems/surrounded-regions) | Medium | [C++](./algorithms/surrounded_regions.cpp) | `Union Find` |
| 131 | [Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning) | Medium | [C++](./algorithms/palindrome_partitioning.cpp) | `DFS` |
| 133 | [Clone Graph](https://leetcode.com/problems/clone-graph/) | Medium | [C++](./algorithms/clone_graph.cpp) [Python3](./algorithms/clone_graph.py) | `Hash Table` `DFS` `BFS` |
| 136 | [Single Number](https://leetcode.com/problems/single-number) | Easy | [Python](./algorithms/single_number.py) | `Bit Manipulation` |
| 137 | [Single Number II](https://leetcode.com/problems/single-number-ii) | Medium | [C++](./algorithms/single_number2.cpp) | `Bit Manipulation` |
| 138 | [Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer) | Medium | [C++](./algorithms/copy_list_with_random_pointer.cpp) | `Linked List` |
| 139 | [Word Break](https://leetcode.com/problems/word-break/submissions) | Medium | [C++](./algorithms/word_break.cpp) | `Dynamic Programming` |
| 140 | [Word Break II](https://leetcode.com/problems/word-break-ii) | Hard | [C++](./algorithms/word_break2.cpp) | `DFS` `Dynamic Programming` |
| 141 | [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle) | Easy | [C++](./algorithms/linked_list_cycle.cpp) | `Linked List` `Two Pointers` |
| 142 | [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii) | Medium | [C++](./algorithms/linked_list_cycle2.cpp) | `Hash Table` `Two Pointers` |
| 143 | [Reorder List](https://leetcode.com/problems/reorder-list) | Medium | [C](./algorithms/reorder_list.c) [C++](./algorithms/reorder_list.cpp) | `Recursion` |
| 144 | [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal) | Medium | [C++](./algorithms/binary_tree_preorder_traversal.cpp) | `Tree` `Stack` |
| 145 | [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal) | Hard | [C++](./algorithms/binary_tree_postorder_traversal.cpp) | `Tree` `Stack` |
| 146 | [LRU Cache](https://leetcode.com/problems/lru-cache) | Medium | [C++](./algorithms/lru_cache.cpp) | `Design` |
| 147 | [Insertion Sort List](https://leetcode.com/problems/insertion-sort-list) | Medium | [C](./algorithms/insertion_sort_list.c) |
| 148 | [Sort List](https://leetcode.com/problems/sort-list) | Medium | [C++](./algorithms/sort_list.cpp) [Python3](./algorithms/sort_list.py) | `Sorting` `Merge Sort` |
| 149 | [Max Points on a Line](https://leetcode.com/problems/max-points-on-a-line) | Hard | [C++](./algorithms/max_points.cpp) | `Math` |
| 150 | [Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/) | Medium | [C++](./algorithms/eval_rpn.cpp) | `Stack` |
| 151 | [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string) | Medium | [C++](./algorithms/reverse_words.cpp) | |
| 152 | [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray) | Medium | [C++](./algorithms/maximum_product_subarray.cpp) | `Dynamic Programming` |
| 153 | [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array) | Medium | [C](./algorithms/find_minimum.c) [C++](./algorithms/find_minimum.cpp) | `Binary Search` |
| 154 | [Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii) | Hard | [C](./algorithms/find_minimum2.c) [C++](./algorithms/find_minimum2.cpp) | `Binary Search` |
| 155 | [Min Stack](https://leetcode.com/problems/min-stack) | Easy | [C++](./algorithms/min_stack.cpp) [Python](./algorithms/min_stack.py) | `Stack` `Design` |
| 160 | [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists) | Easy | [C++](./algorithms/intersection_of_linked_lists.cpp) | `Two Pointers` |
| 162 | [Find Peak Element](https://leetcode.com/problems/find-peak-element) | Medium | [C++](./algorithms/find_peak_element.cpp) | `Binary Search` |
| 163 | [Missing Ranges](https://leetcode.com/problems/missing-ranges/) | Easy | [C++](./algorithms/missing_ranges.cpp) | `Array` |
| 164 | [Maximum Gap](https://leetcode.com/problems/maximum-gap/description/) | Hard | [C++](./algorithms/maximum_gap.cpp) | `Sorting` `Bucket Sort` |
| 165 | [Compare Version Numbers](https://leetcode.com/problems/compare-version-numbers) | Medium | [C++](./algorithms/compare_version_numbers.cpp) [Python3](./algorithms/compare_version_numbers.py) | `String` |
| 167 | [Two Sum II - Input array is sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted) | Easy | [C++](./algorithms/two_sum2.cpp) |
| 168 | [Excel Sheet Column Title](https://leetcode.com/problems/excel-sheet-column-title) | Easy | [C++](./algorithms/excel_sheet_column_title.cpp) | `Math` |
| 169 | [Majority Element](https://leetcode.com/problems/majority-element) | Easy | [C++](./algorithms/majority_element.cpp) | `Array` `Sorting` `Hash Table` |
| 171 | [Excel Sheet Column Number](https://leetcode.com/problems/excel-sheet-column-number/) | Easy | [C++](./algorithms/excel_sheet_column_number.cpp) | `Math` `String` |
| 173 | [Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator) | Medium | [C++](./algorithms/binary_search_tree_iterator.cpp) | `Tree` `Stack` |
| 175 | [Combine Two Tables](https://leetcode.com/problems/combine-two-tables) | Easy | [MySQL](./database/combine_two_tables.sql) | Database |
| 176 | [Second Highest Salary](https://leetcode.com/problems/second-highest-salary) | Easy | [MySQL](./database/second_highest_salary.sql) | Database |
| 177 | [Nth Highest Salary](https://leetcode.com/problems/nth-highest-salary) | Medium | [MySQL](./database/nth_highest_salary.sql) | Database |
| 178 | [Rank Scores](https://leetcode.com/problems/rank-scores/) | Medium | [MySQL](./database/rank_scores.sql) | Database |
| 179 | [Largest Number](https://leetcode.com/problems/largest-number) | Medium | [Python](./algorithms/largest_number.py) |
| 189 | [Rotate Array](https://leetcode.com/problems/rotate-array) | Easy | [C](./algorithms/rotate_array.c) | `Array` |
| 197 | [Rising Temperature](https://leetcode.com/problems/rising-temperature) | Easy | [MySQL](./database/rising_temperature.sql) |
| 190 | [Reverse Bits](https://leetcode.com/problems/reverse-bits) | Easy | [C++](./algorithms/reverse_bits.cpp) | `Bit Manipulation` |
| 191 | [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits) | Easy | [C++](./algorithms/number_of_bits.cpp) | `Bit Manipulation` |
| 192 | [Word Frequency](https://leetcode.com/problems/word-frequency) | Medium | [Bash](./shell/word_frequency.sh) |
| 193 | [Valid Phone Numbers](https://leetcode.com/problems/valid-phone-numbers) | Easy | [Bash](./shell/valid_phone_numbers.sh) |
| 194 | [Transpose File](https://leetcode.com/problems/transpose-file) | Medium | [Bash](./shell/transpose_file.sh) |
| 195 | [Tenth Line](https://leetcode.com/problems/tenth-line) | Easy | [Bash](./shell/tenth_line.sh) |
| 196 | [Delete Duplicate Emails](https://leetcode.com/problems/delete-duplicate-emails) | Easy | [MySQL](./database/delete_duplicate_emails.sql) |
| 198 | [House Robber](https://leetcode.com/problems/house-robber) | Easy | [C++](./algorithms/house_robber.cpp) | `Dynamic Programming` |
| 199 | [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view) | Medium | [C++](./algorithms/binary_tree_right_side_view.cpp) | `BFS` |
| 200 | [Number of Islands](https://leetcode.com/problems/number-of-islands) | Medium | [C++](./algorithms/number_of_islands.cpp) | `Union Find` |
| 202 | [Happy Number](https://leetcode.com/problems/happy-number) | Easy | [C++](./algorithms/happy_number.cpp) [Go](./algorithms/happy_number.go) [Python3](./algorithms/happy_number.py) | `Hash Table` `Two Pointers` |
| 203 | [Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements) | Easy | [C++](./algorithms/remove_linked_list_elements.cpp) | `Linked List` |
| 204 | [Count Primes](https://leetcode.com/problems/count-primes) | Easy | [C++](./algorithms/count_primes.cpp) | `Math` |
| 205 | [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings) | Easy | [Go](./algorithms/isomorphic_strings.go) | `Hash Table` |
| 206 | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list) | Easy | [C++](./algorithms/reverse_linked_list.cpp) [Python3](./algorithms/reverse_linked_list.py) | `Linked List` `Recursion` |
| 208 | [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree) | Medium | [C++](./algorithms/implement_trie.cpp) | `Design` `Trie` |
| 209 | [Course Schedule](https://leetcode.com/problems/course-schedule/) | Medium | [C++](./algorithms/course_schedule.cpp) | `DFS` `Graph` |
| 215 | [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) | Medium | [C++](./algorithms/find_kth_larguest.cpp) | `Sorting` `Priority Queue`|
| 216 | [Combination Sum III](https://leetcode.com/problems/combination-sum-iii) | Medium | [C++](./algorithms/combination_sum3.cpp) |
| 217 | [Contains Duplicate](https://leetcode.com/problems/contains-duplicate) | Easy | [C++](./algorithms/contains_duplicate.cpp) | `Hash Table` `Sorting` |
| 219 | [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii) | Easy | [C++](./algorithms/contains_duplicate2.cpp) |
| 220 | [Contains Duplicate III](https://leetcode.com/problems/contains-duplicate-iii) | Medium | [C++](./algorithms/contains_duplicate3.cpp) |
| 222 | [Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes/) | Medium | [C++](./algorithms/count_complete_tree_nodes.cpp) | `Tree` `DFS` |
| 224 | [Basic Calculator](https://leetcode.com/problems/basic-calculator/) | Hard | [C++](./algorithms/basic_calculator.cpp) | `String` `Stack` |
| 225 | [Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues) | Easy | [C++](./algorithms/implement_stack_using_queues.cpp) | `Stack` `Queue` |
| 226 | [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree) | Easy | [C++](./algorithms/invert_binary_tree.cpp) | `Tree` `DFS` |
| 227 | [Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii/) | Medium | [C++](./algorithms/basic_calculator2.cpp) | `String` `Stack` |
| 228 | [Summary Ranges](https://leetcode.com/problems/summary-ranges/) | Easy | [Python3](./algorithms/summary_ranges.py) | `Array` |
| 230 | [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/) | Medium | [C++](./algorithms/kth_smallest_element.cpp) | `Tree` `BFS` |
| 232 | [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks) | Easy | [C++](./algorithms/implement_queue_using_stacks.cpp) | `Stack` `Queue` |
| 234 | [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list) | Medium | [C++](./algorithms/palindrome_linked_list.cpp) | `Linked List` `Two Pointers` |
| 235 | [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree) | Easy | [C++](./algorithms/lowest_common_ancestor_bst.cpp) | `Tree` `DFS` |
| 236 | [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree) | Medium | [C++](./algorithms/lowest_common_ancestor.cpp) [Go](./algorithms/lowest_common_ancestor.go) | `Tree` `DFS` |
| 237 | [Delete Node in a Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list) | Easy | [C++](./algorithms/delete_node_in_linked_list.cpp) | `Linked List` |
| 238 | [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) | Medium | [C++](./algorithms/product_except_self.cpp) | `Array` `Prefix Sum` |
| 242 | [Valid Anagram](https://leetcode.com/problems/valid-anagram) | Easy | [C++](./algorithms/valid_anagram.cpp) | `String` `Hash Table` |s
| 257 | [Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths) | Easy | [C++](./algorithms/binary_tree_paths.cpp) |
| 258 | [Add Digits](https://leetcode.com/problems/add-digits/) | Easy | [Python3](./algorithms/add_digits.py) | `Math` |
| 263 | [Ugly Number](https://leetcode.com/problems/ugly-number) | Easy | [Python](./algorithms/ugly_number.py) |
| 268 | [Missing Number](https://leetcode.com/problems/missing-number) | Easy | [C++](./algorithms/missing_number.cpp) | `Array` `Math` |
| 274 | [H-Index](https://leetcode.com/problems/h-index/) | Medium | [C++](./algorithms/h_index.cpp) | `Sorting` |
| 278 | [First Bad Version](https://leetcode.com/problems/first-bad-version) | Easy | [C++](./algorithms/first_bad_version.cpp) | `Binary Search` |
| 283 | [Move Zeroes](https://leetcode.com/problems/move-zeroes) | Easy | [C++](./algorithms/move_zeroes.cpp) | `Two Pointers` |
| 286 | [Walls and Gates](https://leetcode.com/problems/walls-and-gates/) | Medium | [C++](./algorithms/walls_and_gates.cpp) | `Matrix` `DFS` |
| 287 | [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number) | Medium | [C++](./algorithms/find_the_duplicate_number.cpp) | `Two Pointers` |
| 292 | [Nim Game](https://leetcode.com/problems/nim-game) | Easy | [C++](./algorithms/nim_game.cpp) | `Brainteaser` |
| 295 | [Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/) | Hard | [C++](./algorithms/median_finder.cpp) | `Sorting` `Priority Queue`|
| 297 | [Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree) | Hard | [C++](./algorithms/serialize_binary_tree.cpp) | `Tree` `DFS` |
| 300 | [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence) | Medium | [C++](./algorithms/longest_increasing_subsequence.cpp) | `Dynamic Programming` |
| 303 | [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/) | Easy | [C++](./algorithms/range_sum_query.cpp) | `Array` |
| 322 | [Coin Change](https://leetcode.com/problems/coin-change/) | Medium | [C++](./algorithms/coin_change.cpp) | `Dynamic Programming` |
| 326 | [Power of Three](https://leetcode.com/problems/power-of-three) | Easy | [C++](./algorithms/power_of_three.cpp) | `Math` |
| 328 | [Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list) | Medium | [C++](./algorithms/odd_even_linked_list.cpp) | `Linked List` |
| 334 | [Increasing Triplet Subsequence](https://leetcode.com/problems/increasing-triplet-subsequence) | Medium | [C++](./algorithms/increasing_triplet_subsequence.cpp) | |
| 338 | [Counting Bits](https://leetcode.com/problems/counting-bits/) | Easy | [C++](./algorithms/count_bits.cpp) | `Dynamic Programming` |
| 344 | [Reverse String](https://leetcode.com/problems/reverse-string) | Easy | [C++](./algorithms/reverse_string.cpp) | `Two Pointers` |
| 347 | [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) | Medium | [C++](./algorithms/top_k_frequent_elements.cpp) | `Hash Table` `Heap` |
| 348 | [Design Tic-Tac-Toe](https://leetcode.com/problems/design-tic-tac-toe/) | Medium | [C++](./algorithms/tic_tac_toe.cpp) | `Matrix` |
| 349 | [Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays) | Easy | [C++](./algorithms/intersection_of_two_arrays.cpp) | `Hash Table` |
| 350 | [Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii) | Easy | [C++](./algorithms/intersection_of_two_arrays2.cpp) | `Hash Table` |
| 367 | [Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square) | Easy | [C++](./algorithms/valid_perfect_square.cpp) | `Binary Search` |
| 368 | [Largest Divisible Subset](https://leetcode.com/problems/largest-divisible-subset/) | Medium | [C++](./algorithms/largest_divisible_subset.cpp) | `Dynamic Programming` |
| 371 | [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers) | Easy | [C++](./algorithms/sum_of_two_integers.cpp) |
| 374 | [Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower) | Easy | [C++](./algorithms/guess_number_higher_or_lower.cpp) | `Binary Search` |
| 377 | [Combination Sum IV](https://leetcode.com/problems/combination-sum-iv) | Medium | [C++](./algorithms/combination_sum4.cpp) |
| 382 | [Linked List Random Node](https://leetcode.com/problems/linked-list-random-node/) | Medium | [C++](./algorithms/linked_list_random_node.cpp) | `Linked List` |
| 383 | [Ransom Note](https://leetcode.com/problems/ransom-note/) | Easy | [C++](./algorithms/ransom_note.cpp)  [Python3](./algorithms/ransom_note.py) | `Hash Table` |
| 384 | [Shuffle an Array](https://leetcode.com/problems/shuffle-an-array) | Medium | [C++](./algorithms/shuffle_an_array.cpp) | `Design` |
| 386 | [Lexicographical Numbers](https://leetcode.com/problems/lexicographical-numbers) | Medium | [C++](./algorithms/lexicographical_numbers.cpp) | `DFS` |
| 387 | [First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string) | Easy | [C++](./algorithms/first_unique_character.cpp) | `Hash Table` |
| 389 | [Find the Difference](https://leetcode.com/problems/find-the-difference/) | Easy | [C++](./algorithms/find_the_difference.cpp) | `Hash Table` `Bit Manipulation` |
| 392 | [Is Subsequence](https://leetcode.com/problems/is-subsequence/) | Easy | [C++](./algorithms/is_subsequence.cpp) [Python3](./algorithms/is_subsequence.py) | `String` |
| 397 | [Integer Replacement](https://leetcode.com/problems/integer-replacement) | Medium | [C++](./algorithms/integer_replacement.cpp) |
| 404 | [Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves) | Easy | [C++](./algorithms/sum_of_left_leaves.cpp) | `Tree` |
| 409 | [Longest Palindrome](https://leetcode.com/problems/longest-palindrome/) | Easy | [C++](./algorithms/longest_palindrome.cpp) | `String` `Hash Table` |
| 410 | [Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum) | Hard | [C++](./algorithms/split_array_largest_sum.cpp) | `Binary Search` |
| 412 | [Fizz Fuzz](https://leetcode.com/problems/fizz-buzz) | Easy | [C++](./algorithms/fizz_buzz.cpp) | `Math` |
| 414 | [Third Maximum Number](https://leetcode.com/problems/third-maximum-number/) | Easy | [C++](./algorithms/third_maximum_number.cpp) | `Sorting` |
| 415 | [Add Strings](https://leetcode.com/problems/add-strings) | Easy | [C++](./algorithms/add_strings.cpp) |
| 429 | [N-ary Tree Level Order Traversal](https://leetcode.com/problems/n-ary-tree-level-order-traversal) | Medium | [C++](./algorithms/nary_tree_level_order_traversal.cpp) | `Tree` `BFS` |
| 430 | [Flatten a Multilevel Doubly Linked List](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list) | Medium | [C++](./algorithms/flatten_multilevel_linked_list.cpp) | `Linked List` |
| 437 | [Path Sum III](https://leetcode.com/problems/path-sum-iii) | Easy | [C++](./algorithms/path_sum3.cpp) |
| 442 | [Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/) | Medium | [C++](./algorithms/find_duplicates.cpp) |
| 443 | [String Compression](https://leetcode.com/problems/string-compression) | Easy | [C++](./algorithms/string_compression.cpp) |
| 448 | [Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/) | Easy | [C++](./algorithms/find_disappeared_numbers.cpp) |
| 451 | [Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/) | Medium | [C++](./algorithms/sort_characters_by_frequency.cpp) [Python3](./algorithms/sort_characters_by_frequency.py)| `Hash Table` `Sorting` |
| 452 | [Minimum Number of Arrows to Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/) | Medium | [C++](./algorithms/minimum_arrow_shots.cpp) [Python3](./algorithms/minimum_arrow_shots.py) | `Sorting` |
| 455 | [Assign Cookies](https://leetcode.com/problems/assign-cookies/description/) | Easy | [C++](./algorithms/assign_cookies.cpp) | `Sorting` `Two Pointers` |
| 461 | [Hamming Distance](https://leetcode.com/problems/hamming-distance) | Easy | [C++](./algorithms/hamming_distance.cpp) | `Bit Manipulation` |
| 477 | [Total Hamming Distance](https://leetcode.com/problems/total-hamming-distance) | Medium| [C++](./algorithms/total_hamming_distance.cpp) | `Math` `Bit Manipulation` |
| 480 | [Sliding Window Median](https://leetcode.com/problems/sliding-window-median) | Hard | [C++](./algorithms/median_sliding_window.cpp) | `Array` |
| 485 | [Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones) | Easy | [C++](./algorithms/max_consecutive_ones.cpp) | `Array` |
| 487 | [Max Consecutive Ones II](https://leetcode.com/problems/max-consecutive-ones-ii) | Medium | [C++](./algorithms/max_consecutive_ones2.cpp) | `Array` `Two Pointers`|
| 491 | [Increasing Subsequences](https://leetcode.com/problems/increasing-subsequences) | Medium | [C++](./algorithms/increasing_subsequences.cpp) |
| 501 | [Find Mode in Binary Search Tree](https://leetcode.com/problems/find-mode-in-binary-search-tree) | Easy | [C++](./algorithms/find_mode_in_binary_search_tree.cpp) |
| 509 | [Fibonacci Number](https://leetcode.com/problems/fibonacci-number) | Easy | [C++](./algorithms/fibonacci_number.cpp) | `Array` `Dynamic Programming` |
| 523 | [Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum) | Medium | [C++](./algorithms/continuous_subarray_sum.cpp) | |
| 524 | [Longest Word in Dictionary through Deleting](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting) | Medium | [C++](./algorithms/longest_word_through_deleting.cpp) | `Sorting` `Two Pointers` |
| 540 | [Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array) | Medium | [C++](./algorithms/single_non_duplicate.cpp) | `Bit Manipulation` `Binary Search` |
| 541 | [Reverse String II](https://leetcode.com/problems/reverse-string-ii) | Easy | [C++](./algorithms/reverse_string2.cpp) | |
| 542 | [01 Matrix](https://leetcode.com/problems/01-matrix/) | Medium | [C++](./algorithms/update_matrix.cpp) | `BFS` `Dynamic Programming` |
| 543 | [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/) | Easy | [C++](./algorithms/diameter_of_binary_tree.cpp) | `Tree` `DFS` |
| 560 | [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k) | Medium | [C++](./algorithms/subarray_sum_equals_k.cpp) | `Array` |
| 563 | [Binary Tree Tilt](https://leetcode.com/problems/binary-tree-tilt/) | Easy | [C++](./algorithms/binary_tree_tilt.cpp) | `Tree` `DFS` |
| 567 | [Permutation in String](https://leetcode.com/problems/permutation-in-string/) | Medium | [C++](./algorithms/permutation_in_string.cpp) | `Sorting` |
| 594 | [Longest Harmonious Subsequence](https://leetcode.com/problems/longest-harmonious-subsequence/) | Easy | [C++](./algorithms/find_lhs.cpp) | `Hash Table` |
| 599 | [Minimum Index Sum of Two Lists](https://leetcode.com/problems/minimum-index-sum-of-two-lists) | Easy | [C++](./algorithms/minimum_index_sum.cpp) |
| 623 | [Add One Row to Tree](https://leetcode.com/problems/add-one-row-to-tree) | Medium | [C++](./algorithms/add_one_row_to_tree.cpp) |
| 628 | [Maximum Product of Three Numbers](https://leetcode.com/problems/maximum-product-of-three-numbers/) | Easy | [Go](./algorithms/maximum_product_of_three_numbers.go) |
| 629 | [K Inverse Pairs Array](https://leetcode.com/problems/k-inverse-pairs-array) | Hard | [C++](./algorithms/k_inverse_paris_array.cpp) | `Dynamic Programming` |
| 645 | [Set Mismatch](https://leetcode.com/problems/set-mismatch) | Easy | [C++](./algorithms/set_mismatch.cpp) |
| 653 | [Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst) | Easy | [C++](./algorithms/two_sum4.cpp) |
| 658 | [Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements) | Medium | [C++](./algorithms/find_k_closest_elements.cpp) | `Binary Search` |
| 662 | [Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree/) | Medium | [C++](./algorithms/maximum_width_of_binary_tree.cpp) | `Binary Tree` `BFS` |
| 670 | [Maximum Swap](https://leetcode.com/problems/maximum-swap/) | Medium | [C++](./algorithms/maximum_swap.cpp) | `Math` |
| 680 | [Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii) | Easy | [C++](./algorithms/valid_palindrome2.cpp) | `String` `Two Pointers` |
| 704 | [Binary Search](https://leetcode.com/problems/binary-search) | Easy | [C++](./algorithms/binary_search.cpp) | `Array` `Binary Search` |
| 705 | [Design HashSet](https://leetcode.com/problems/design-hashset) | Easy | [C++](./algorithms/design_hashset.cpp) | `Bit Manipulation` `Hash Table` |
| 706 | [Design HashMap](https://leetcode.com/problems/design-hashmap) | Easy | [C++](./algorithms/design_hashmap.cpp) | `Array` `Hash Table` |
| 707 | [Design Linked List](https://leetcode.com/problems/design-linked-list) | Medium | [C++](./algorithms/design_linked_list.cpp) | `Linked List` |
| 716 | [Max Stack](https://leetcode.com/problems/max-stack) | Hard | [C++](./algorithms/max_stack.cpp) | `Ordered Set` `Priority Queue`|
| 719 | [Find K-th Smallest Pair Distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance) | Hard | [C++](./algorithms/find_kth_smallest_pair_distance.cpp) | `Binary Search` |
| 733 | [Flood Fill](https://leetcode.com/problems/flood-fill/) | Easy | [C++](./algorithms/flood_fill.cpp) | `Array` `DFS` |
| 739 | [Daily Temperatures](https://leetcode.com/problems/daily-temperatures) | Medium | [C++](./algorithms/daily_temperatures.cpp) | `Stack` |
| 744 | [Find Smallest Letter Greater Than Target](https://leetcode.com/problems/find-smallest-letter-greater-than-target) | Easy | [C++](./algorithms/find_smallest_letter.cpp) | `Binary Search` |
| 763 | [Partition Labels](https://leetcode.com/problems/partition-labels/) | Medium | [C++](./algorithms/partition_labels.cpp) | `Hash Table` |
| 765 | [Couples Holding Hands](https://leetcode.com/problems/couples-holding-hands) | Hard | [C++](./algorithms/couples_holding_hands.cpp) | `Union Find` |
| 769 | [Max Chunks To Make Sorted](https://leetcode.com/problems/max-chunks-to-make-sorted/) | Medium | [C++](./algorithms/max_chunks_to_sorted.cpp) | `Array` |
| 772 | [772. Basic Calculator III](https://leetcode.com/problems/basic-calculator-iii/) | Hard | [C++](./algorithms/basic_calculator3.cpp) | `String` `Stack` |
| 779 | [K-th Symbol in Grammar](https://leetcode.com/problems/k-th-symbol-in-grammar) | Medium | [C++](./algorithms/kth_symbol_in_grammar.cpp) | `Recursion` |
| 788 | [Rotated Digits](https://leetcode.com/problems/rotated-digits) | Easy | [C++](./algorithms/rotated_digits.cpp) | `Dynamic Programming` |
| 796 | [Rotate String](https://leetcode.com/problems/rotate-string) | Easy | [C++](./algorithms/rotate_string.cpp) | `String` |
| 799 | [Champagne Tower](https://leetcode.com/problems/champagne-tower/) | Medium| [C++](./algorithms/champagne_tower.cpp) | `Dynamic Programming` |
| 855 | [Exam Room](https://leetcode.com/problems/exam-room/) | Medium | [C++](./algorithms/exam_room.cpp) | `Ordered Set` |
| 867 | [Transpose Matrix](https://leetcode.com/problems/transpose-matrix/) | Easy | [C++](./algorithms/transpose_matrix.cpp) | `Matrix` |
| 876 | [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/) | Easy | [C++](./algorithms/middle_node.cpp) | `Linked List` `Two Pointers` |
| 899 | [Orderly Queue](https://leetcode.com/problems/orderly-queue) | Hard | [C++](./algorithms/orderly_queue.cpp) | `Math` `String` |
| 905 | [Sort Array By Parity](https://leetcode.com/problems/sort-array-by-parity/) | Easy | [C++](./algorithms/sort_array_by_parity.cpp) | `Array` `Two Pointers` |
| 912 | [Sort an Array](https://leetcode.com/problems/sort-an-array) | Medium | [C++](./algorithms/sort_array.cpp) | `Array` `Merge Sort` `Heap Sort` |
| 921 | [Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/) | Medium | [C++](./algorithms/min_add_to_make_valid.cpp) | `String` `Stack` |
| 922 | [Sort Array By Parity II](https://leetcode.com/problems/sort-array-by-parity-ii/) | Easy | [C++](./algorithms/sort_array_by_parity2.cpp) | `Array` `Two Pointers` |
| 938 | [Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst/) | Easy | [C++](./algorithms/range_sum_bst.cpp) | `DFS` |
| 965 | [Univalued Binary Tree](https://leetcode.com/problems/univalued-binary-tree) | Easy | [C++](./algorithms/univalued_binary_tree.cpp) | `BFS` |
| 973 | [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/) | Medium | [C++](./algorithms/k_closest_points.cpp) | `Array` `Sorting` `Priority Queue` |
| 977 | [Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/) | Easy | [C++](./algorithms/sorted_squares.cpp) | `Array` `Two Pointers` |
| 981 | [Time Based Key-Value Store](https://leetcode.com/problems/time-based-key-value-store/) | Medium | [C++](./algorithms/time_map.cpp) | `Hash Table` |
| 989 | [Add to Array-Form of Integer](https://leetcode.com/problems/add-to-array-form-of-integer/) | Easy | [C++](./algorithms/add_to_array_form.cpp) | `Array` `Math` |
| 993 | [Cousins in Binary Tree](https://leetcode.com/problems/cousins-in-binary-tree) | Easy | [C++](./algorithms/cousins_in_binary_tree.cpp) | `Tree` `DFS` |
| 997 | [Find the Town Judge](https://leetcode.com/problems/find-the-town-judge/) | Easy | [C++](./algorithms/find_judge.cpp) | `Graph` |
| 1004 | [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii) | Medium | [C++](./algorithms/max_consecutive_ones3.cpp) | `Array` `Two Pointers` |
| 1051 | [Height Checker](https://leetcode.com/problems/height-checker/description/) | Easy | [C++](./algorithms/height_checker.cpp) | `Array` `Sorting` `Counting Sort` |
| 1091 | [Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/) | Medium | [C++](./algorithms/shortest_path.cpp) | `Array` `BFS` |
| 1093 | [Statistics from a Large Sample](https://leetcode.com/problems/statistics-from-a-large-sample/) | Medium | [C++](./algorithms/sample_stats.cpp) | `Array` `Math` |
| 1134 | [Armstrong Number]()https://leetcode.com/problems/armstrong-number/ | Easy | [C++](./algorithms/armstrong_number.cpp) | `Math` |
| 1206 | [Design Skiplist](https://leetcode.com/problems/design-skiplist) | Hard | [C++](./algorithms/design_skiplist.cpp) | `Linked List` |
| 1207 | [Unique Number of Occurrences](https://leetcode.com/problems/unique-number-of-occurrences/) | Easy | [C++](./algorithms/unique_occurrences.cpp) | `Hash Table` |
| 1247 | [Minimum Swaps to Make Strings Equal](https://leetcode.com/problems/minimum-swaps-to-make-strings-equal) | Medium | [C++](./algorithms/minimum_swaps_equal.cpp) | `Math` `String` |
| 1288 | [Remove Covered Intervals](https://leetcode.com/problems/remove-covered-intervals/) | Medium | [C++](./algorithms/remove_covered_intervals.cpp) | `Array` `Sorting` |
| 1365 | [How Many Numbers Are Smaller Than the Current Number]()https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/ | Easy | [C++](./algorithms/smaller_numbers.cpp) | `Sorting` `Hash Table` |
| 1366 | [Rank Teams by Votes](https://leetcode.com/problems/rank-teams-by-votes) | Medium | [C++](./algorithms/rank_teams.cpp) | `Array` `Sorting` |
| 1381 | [Design a Stack With Increment Operation](https://leetcode.com/problems/design-a-stack-with-increment-operation/) | Medium | [C++](./algorithms/custom_stack.cpp) | `Array` `Stack` |
| 1382 | [Balance a Binary Search Tree](https://leetcode.com/problems/balance-a-binary-search-tree/) | Medium | [C++](./algorithms/balance_bst.cpp) | `Binary Search Tree` |
| 1539 | [Kth Missing Positive Number](https://leetcode.com/problems/kth-missing-positive-number/) | Easy | [C++](./algorithms/kth_missing_positive_number.cpp) | `Array` `Hash Table` |
| 1566 | [Detect Pattern of Length M Repeated K or More Times](https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/) | Easy | [C++](./algorithms/contains_pattern.cpp) | `Array` `Enumeration` |
| 1641 | [Count Sorted Vowel Strings](https://leetcode.com/problems/count-sorted-vowel-strings) | Medium | [C++](./algorithms/count_sorted_vowel_strings.cpp) | `Dynamic Programming` |
| 1679 | [Max Number of K-Sum Pairs](https://leetcode.com/problems/max-number-of-k-sum-pairs) | Medium | [C++](./algorithms/max_number_of_ksum_pairs.cpp) | `Hash Table` |
| 1720 | [Decode XORed Array](https://leetcode.com/problems/decode-xored-array) | Easy | [C++](./algorithms/decode_xored_array.cpp) | `Bit Manipulation` |
| 1726 | [Tuple with Same Product](https://leetcode.com/problems/tuple-with-same-product/) | Medium | [C++](./algorithms/tuple_same_product.cpp) | `Hash Map` `Math` |
| 1765 | [Map of Highest Peak](https://leetcode.com/problems/map-of-highest-peak/) | Medium | [C++](./algorithms/highest_peak.cpp) | `BFS` |
| 1769 | [Minimum Number of Operations to Move All Balls to Each Box](https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/) | Medium | [C++](./algorithms/min_operations.cpp) | `Prefix Sum` |
| 1910 | [Remove All Occurrences of a Substring](https://leetcode.com/problems/remove-all-occurrences-of-a-substring/) | Medium | [C++](./algorithms/remove_occurrences.cpp) | `String` |
| 2032 | [Two Out of Three](https://leetcode.com/problems/two-out-of-three) | Easy | [C++](./algorithms/two_out_of_three.cpp) | `Set` `Map` |
| 2092 | [Find All People With Secret](https://leetcode.com/problems/find-all-people-with-secret/) | Hard | [C++](./algorithms/find_all_people.cpp) | `Union Find` |
| 2108 | [Find First Palindromic String in the Array](https://leetcode.com/problems/find-first-palindromic-string-in-the-array/) | Easy | [C++](./algorithms/first_palindrome.cpp) | `Two Pointers` |
| 2177 | [Find Three Consecutive Integers That Sum to a Given Number](https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/) | Medium | [C++](./algorithms/sum_of_three.cpp) | `Math` |
| 2293 | [Min Max Game](https://leetcode.com/problems/min-max-game/) | Easy | [C++](./algorithms/min_max_game.cpp) | `Array` |
| 2349 | [Design a Number Container System](https://leetcode.com/problems/design-a-number-container-system/) | Medium | [C++](./algorithms/number_containers.cpp) | `Hash Table` `Ordered Set` `Priority Queue` |
| 2379 | [Minimum Recolors to Get K Consecutive Black Blocks](https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/) | Easy | [C++](./algorithms/minimum_recolors.cpp) | `Sliding Window` |
| 2381 | [Shifting Letters II](https://leetcode.com/problems/shifting-letters-ii/) | Medium | [C++](./algorithms/shifting_letters2.cpp) | `Array` |
| 2359 | [Find Closest Node to Given Two Nodes](https://leetcode.com/problems/find-closest-node-to-given-two-nodes/) | Medium | [C++](./algorithms/cloest_meeting_node.cpp) | `BFS` |
| 2657 | [Find the Prefix Common Array of Two Arrays]()https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/ | Medium | [C++](./algorithms/prefix_common_array.cpp) | `Array` |
| 2864 | [Maximum Odd Binary Number](https://leetcode.com/problems/maximum-odd-binary-number/) | Easy | [C++](./algorithms/maximum_odd_number.cpp) | `Math` `String` |
| 2951 | [Find the Peaks](https://leetcode.com/problems/find-the-peaks/) | Easy | [C++](./algorithms/find_the_peaks.cpp) | `Array` |
| 3024 | [Type of Triangle](https://leetcode.com/problems/type-of-triangle/) | Easy | [C++](./algorithms/triangle_type.cpp) | `Math` |
| 3151 | [Special Array I](https://leetcode.com/problems/special-array-i/) | Easy | [C++](./algorithms/special_array1.cpp) | `Array` |
| 3174 | [Clear Digits](https://leetcode.com/problems/clear-digits/) | Easy | [C++](./algorithms/clear_digits.cpp) | `Stack` |
| 3285 | [Find Indices of Stable Mountains](https://leetcode.com/problems/find-indices-of-stable-mountains/) | Easy | [C++](./algorithms/stable_mountains.cpp) | `Array` |
| 3392 | [Count Subarrays of Length Three With a Condition](https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/) | Easy | [C++](./algorithms/count_subarrays.cpp) | `Array` |
| 3432 | [Count Partitions with Even Sum Difference]()https://leetcode.com/problems/count-partitions-with-even-sum-difference/ | Easy | [C++](./algorithms/count_partitions.cpp) | `Array` `Math` |
