/*
 * =====================================================================================
 *
 *       Filename:  fruits_into_baskets3.cpp
 *
 *    Description:  3479. Fruits Into Baskets III
 *                  https://leetcode.com/problems/fruits-into-baskets-iii/
 *
 *        Version:  1.0
 *        Created:  08/07/2025 11:04:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <tuple>
#include <vector>

#include "gtest/gtest.h"

// Segment tree + binary search
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
 public:
  int numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets) {
    const int n = baskets.size();
    int leaves = 1;
    while (leaves < n) {
      leaves <<= 1;
    }

    const int tree_size = leaves * 2 - 1;
    std::vector<int> seg_tree(tree_size);
    // Initilize all the leaves
    for (int i = 0; i < n; i++) {
      seg_tree[i + leaves - 1] = baskets[i];
    }
    // Build segment tree
    for (int i = leaves - 2; i >= 0; i--) {
      const int l = i * 2 + 1;
      const int r = i * 2 + 2;
      // printf("i = %d, l = %d, r = %d\n", i, l, r);
      seg_tree[i] = std::max(seg_tree[l], seg_tree[r]);
    }

    int count = 0;
    for (int val : fruits) {
      int i = 0;
      if (seg_tree[i] < val) {
        continue;
      }

      // Find the correct index
      while (true) {
        const int l = i * 2 + 1;
        const int r = i * 2 + 2;
        if (l < tree_size && seg_tree[l] >= val) {
          i = l;
        } else if (r < tree_size && seg_tree[r] >= val) {
          i = r;
        } else {
          break;
        }
      }

      // Set as used
      seg_tree[i] = -1;
      while (i > 0) {
        const int p = (i - 1) / 2;
        const int l = p * 2 + 1;
        const int r = p * 2 + 2;
        seg_tree[p] = std::max(seg_tree[l], seg_tree[r]);
        i = p;
      }

      count++;
    }

    return (n - count);
  }
};

TEST(Solution, numOfUnplacedFruits) {
  std::vector<std::tuple<std::vector<int>, std::vector<int>, int>> cases = {
      {{4, 2, 5}, {3, 5, 4}, 1},
      {{3, 6, 1}, {6, 4, 7}, 0},
  };
  for (auto& [fruits, baskets, result] : cases) {
    EXPECT_EQ(Solution().numOfUnplacedFruits(fruits, baskets), result);
  }
}
