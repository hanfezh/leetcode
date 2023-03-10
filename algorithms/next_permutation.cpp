/*
 * =====================================================================================
 *
 *       Filename:  next_permutation.cpp
 *
 *    Description:  31. Next Permutation. Implement next permutation, which rearranges 
 *                  numbers into the lexicographically next greater permutation of
 *                  numbers. If such arrangement is not possible, it must rearrange it 
 *                  as the lowest possible order (ie, sorted in ascending order).
 *
 *        Version:  1.0
 *        Created:  08/21/18 11:10:00
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

using std::vector;

/**
 * 1. Find the largest index k such that nums[k] < nums[k + 1].
 *    If no such index exists, just reverse nums and done.
 * 2. Find the largest index r > k such that nums[k] < nums[r].
 * 3. Swap nums[k] and nums[r].
 * 4. Reverse the sub-array nums[k + 1:].
 */
class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int k = nums.size() - 2;
    while (k >= 0 && nums[k] >= nums[k + 1]) {
      k--;
    }

    if (k < 0) {
      std::reverse(nums.begin(), nums.end());
      return;
    }

    int r = nums.size() - 1;
    while (r > k && nums[r] <= nums[k]) {
      r--;
    }
    std::swap(nums[k], nums[r]);
    std::reverse(nums.begin() + k + 1, nums.end());
  }
};

TEST(Solution, nextPermutation) {
  vector<std::pair<vector<int>, vector<int>>> cases = {
      std::make_pair(vector<int>{1, 2, 3}, vector<int>{1, 3, 2}),
      std::make_pair(vector<int>{3, 2, 1}, vector<int>{1, 2, 3}),
      std::make_pair(vector<int>{1, 1, 5}, vector<int>{1, 5, 1}),
  };
  for (auto& c : cases) {
    Solution().nextPermutation(c.first);
    EXPECT_THAT(c.first, testing::ElementsAreArray(c.second));
  }
}
