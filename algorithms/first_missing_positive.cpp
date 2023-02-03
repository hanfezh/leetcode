/*
 * =====================================================================================
 *
 *       Filename:  first_missing_positive.cpp
 *
 *    Description:  First Missing Positive: Given an unsorted integer array, find the
 *                  smallest missing positive integer.
 *
 *        Version:  1.0
 *        Created:  07/31/18 03:27:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

// Constant extra space
class Solution1 {
 public:
  int firstMissingPositive(std::vector<int>& nums) {
    std::vector<bool> flags(nums.size(), false);
    for (const int n : nums) {
      if ((n < 1) || (n > nums.size())) {
        continue;
      }
      flags[n - 1] = true;
    }

    int fmp = 0;
    for (size_t i = 0; i < flags.size(); i++) {
      if (not flags[i]) {
        fmp = i + 1;
        break;
      }
    }
    if (fmp == 0) {
      fmp = flags.size() + 1;
    }
    return fmp;
  }
};

// No extra space
class Solution2 {
 public:
  int firstMissingPositive(std::vector<int>& nums) {
    nums.push_back(0);
    const int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i] < 1 || nums[i] >= n) {
        nums[i] = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) {
        continue;
      }
      nums[(nums[i]) % n] += n;
    }
    int i = 1;
    while ((i < n) && ((nums[i] / n) > 0)) {
      i++;
    }
    return i;
  }
};

TEST(Solution, firstMissingPositive) {
  std::vector<std::pair<std::vector<int>, int>> cases = {
      std::make_pair(std::vector<int>{0, 3}, 1),
      std::make_pair(std::vector<int>{1, 2, 0}, 3),
      std::make_pair(std::vector<int>{3, 4, -1, 1}, 2),
      std::make_pair(std::vector<int>{7, 8, 9, 11}, 1),
      std::make_pair(std::vector<int>{1, 2, 3, 4}, 5),
      std::make_pair(std::vector<int>{1, 0, -1, 0, -2, 2}, 3),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution1().firstMissingPositive(c.first), c.second);
    EXPECT_EQ(Solution2().firstMissingPositive(c.first), c.second);
  }
}
