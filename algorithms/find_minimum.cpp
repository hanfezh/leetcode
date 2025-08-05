// 153. Find Minimum in Rotated Sorted Array
// Author: xianfeng.zhu@gmail.com

#include <utility>
#include <vector>

#include "gtest/gtest.h"

class Solution {
 public:
  int findMin(std::vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (nums[m] > nums[r]) {
        l = m + 1;
      } else if (nums[m] < nums[r]) {
        r = m;
      } else {
        return nums[m];
      }
    }
    return 0;
  }
};

TEST(Solution, findMin) {
  std::vector<std::pair<std::vector<int>, int>> cases = {
      {{3, 4, 5, 1, 2}, 1},
      {{4, 5, 6, 7, 0, 1, 2}, 0},
      {{11, 13, 15, 17}, 11},
  };
  for (auto& [nums, result] : cases) {
    EXPECT_EQ(Solution().findMin(nums), result);
  }
}
