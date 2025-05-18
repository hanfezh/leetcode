/*
 * =====================================================================================
 *
 *       Filename:  max_chunks_to_sorted.cpp
 *
 *    Description:  769. Max Chunks To Make Sorted
 *                  https://leetcode.com/problems/max-chunks-to-make-sorted/
 *
 *        Version:  1.0
 *        Created:  05/18/2025 22:58:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <utility>
#include <vector>

#include "gtest/gtest.h"

class Solution {
 public:
  int maxChunksToSorted(std::vector<int>& arr) {
    int index_sum = 0;
    int prefix_sum = 0;
    int chunks = 0;
    for (int i = 0; i < arr.size(); i++) {
      index_sum += i;
      prefix_sum += arr[i];
      if (prefix_sum == index_sum) {
        chunks++;
      }
    }
    return chunks;
  }
};

TEST(Solution, maxChunksToSorted) {
  std::vector<std::pair<std::vector<int>, int>> cases = {
      std::make_pair(std::vector<int>{4, 3, 2, 1, 0}, 1),
      std::make_pair(std::vector<int>{1, 0, 2, 3, 4}, 4),
      std::make_pair(std::vector<int>{3, 1, 5, 7, 4, 6, 2, 0}, 1),
  };
  for (auto& [arr, chunks] : cases) {
    EXPECT_EQ(Solution().maxChunksToSorted(arr), chunks);
  }
}
