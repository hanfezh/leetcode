/*
 * =====================================================================================
 *
 *       Filename:  min_subarray_len.cpp
 *
 *    Description:  209. Minimum Size Subarray Sum
 *
 *        Version:  1.0
 *        Created:  10/06/2025 00:00:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <algorithm>
#include <vector>

#include "gtest/gtest.h"

// Sliding window
// Time complexity: O(n)
class Solution {
 public:
  int minSubArrayLen(int target, std::vector<int>& nums) {
    int left = 0;
    int right = 0;
    int len = INT_MAX;
    int sum = 0;
    for (; right < nums.size(); right++) {
      sum += nums[right];
      while (sum >= target) {
        len = std::min(len, right - left + 1);
        sum -= nums[left++];
      }
    }
    return (len == INT_MAX ? 0 : len);
  }
};

TEST(Solution, minSubArrayLen) {
  std::vector<std::tuple<int, std::vector<int>, int>> cases = {
      {7, {2, 3, 1, 2, 4, 3}, 2},
      {4, {1, 4, 4}, 1},
      {11, {1, 1, 1, 1, 1, 1, 1, 1}, 0},
  };
  for (auto& [target, nums, len] : cases) {
    EXPECT_EQ(Solution().minSubArrayLen(target, nums), len);
  }
}
