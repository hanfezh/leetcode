// 485. Max Consecutive Ones
// Refer: https://leetcode.com/problems/max-consecutive-ones
// Author: xianfeng.zhu@gmail.com

#include <algorithm>
#include <utility>
#include <vector>

#include "gtest/gtest.h"

class Solution {
 public:
  int findMaxConsecutiveOnes(std::vector<int>& nums) {
    int prev = -1;
    int max_ones = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 1) {
        if (prev == -1) {
          prev = i;
        }
        max_ones = std::max(max_ones, i - prev + 1);
      } else {
        prev = -1;
      }
    }
    return max_ones;
  }
};

TEST(Solution, findMaxConsecutiveOnes) {
  std::vector<std::pair<std::vector<int>, int>> cases = {
      {{1, 1, 0, 1, 1, 1}, 3},
      {{1, 0, 1, 1, 0, 1}, 2},
  };
  for (auto& [nums, max_ones] : cases) {
    EXPECT_EQ(Solution().findMaxConsecutiveOnes(nums), max_ones);
  }
}
