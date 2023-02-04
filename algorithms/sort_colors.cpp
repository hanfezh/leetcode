/*
 * =====================================================================================
 *
 *       Filename:  sort_colors.cpp
 *
 *    Description:  75. Sort Colors. Given an array with n objects colored red, white or
 *                  blue, sort them in-place so that objects of the same color are
 *                  adjacent, with the colors in the order red, white and blue.
 *
 *        Version:  1.0
 *        Created:  04/21/19 13:31:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <algorithm>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

// Two pointers
class Solution {
 public:
  enum Color {
    Red = 0,
    White = 1,
    Blue = 2,
  };

  void sortColors(std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    for (int i = left; i <= right; i++) {
      // Swap current blue and right red/white
      while (nums[i] == Blue && i < right) {
        if (nums[right] != Blue) {
          std::swap(nums[i], nums[right]);
        }
        right--;
      }

      // Swap current red and left white/blue
      while (nums[i] == Red && i > left) {
        if (nums[left] != Red) {
          std::swap(nums[i], nums[left]);
        }
        left++;
      }
    }
  }
};

TEST(Solution, sortColors) {
  std::vector<std::pair<std::vector<int>, std::initializer_list<int>>> cases = {
      std::make_pair(std::vector<int>{2, 0, 1}, std::initializer_list<int>{0, 1, 2}),
      std::make_pair(std::vector<int>{2, 0, 2, 1, 1, 0},
                     std::initializer_list<int>{0, 0, 1, 1, 2, 2}),
  };
  for (auto& c : cases) {
    Solution().sortColors(c.first);
    EXPECT_THAT(c.first, testing::ElementsAreArray(c.second));
  }
}
