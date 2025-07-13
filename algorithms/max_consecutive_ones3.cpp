// 1004. Max Consecutive Ones III
// Refer: https://leetcode.com/problems/max-consecutive-ones-iii
// Author: xianfeng.zhu@gmail.com

#include <algorithm>
#include <tuple>
#include <vector>

#include "gtest/gtest.h"

// Sliding window, two pointers
class Solution {
 public:
  int longestOnes(std::vector<int>& nums, int k) {
    int prev = 0;
    int used_zeros = 0;
    int max_ones = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        used_zeros++;
      }
      while (used_zeros > k) {
        if (nums[prev] == 0) {
          used_zeros--;
        }
        prev++;
      }
      max_ones = std::max(max_ones, i - prev + 1);
    }
    return max_ones;
  }
};

TEST(Solution, longestOnes) {
  std::vector<std::tuple<std::vector<int>, int, int>> cases{
      {{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}, 2, 6},
      {{0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1}, 3, 10},
  };
  for (auto& [nums, k, max_ones] : cases) {
    EXPECT_EQ(Solution().longestOnes(nums, k), max_ones);
  }
}
