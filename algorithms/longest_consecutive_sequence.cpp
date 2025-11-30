// =====================================================================================
//
//       Filename:  longest_consecutive_sequence.cpp
//
//    Description:  128. Longest Consecutive Sequence. Given an unsorted array of
//                  integers, find the length of the longest consecutive elements
//                  sequence. Your algorithm should run in O(n) complexity.
//
//        Version:  1.0
//        Created:  08/21/2019 09:09:21 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:
//
// =====================================================================================
#include <unordered_set>
#include <utility>
#include <vector>

#include "gtest/gtest.h"

// Hash Set: O(n)
class Solution {
 public:
  int longestConsecutive(std::vector<int>& nums) {
    std::unordered_set<int> hset(nums.begin(), nums.end());

    int res = 0;
    for (int val : hset) {
      if (hset.count(val - 1) > 0) {
        continue;
      }

      // Found the first element of the sequence
      int next = val + 1;
      while (hset.count(next) > 0) {
        next++;
      }
      res = std::max(res, next - val);
    }
    return res;
  }
};

TEST(Solution, longestConsecutive) {
  std::vector<std::pair<std::vector<int>, int>> cases = {
      {{100, 4, 200, 1, 3, 2}, 4},
      {{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}, 9},
      {{1, 0, 1, 2}, 3},
  };
  for (auto& [nums, res] : cases) {
    EXPECT_EQ(Solution().longestConsecutive(nums), res);
  }
}
