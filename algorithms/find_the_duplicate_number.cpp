/*
 * =====================================================================================
 *
 *       Filename:  find_the_duplicate_number.cpp
 *
 *    Description:  287. Find the Duplicate Number.
 *                  https://leetcode.com/problems/find-the-duplicate-number/
 *
 *        Version:  1.0
 *        Created:  03/05/19 11:34:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <algorithm>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

// Modify array, time O(N), space O(1)
class Solution1 {
 public:
  int findDuplicate(std::vector<int>& nums) {
    const int i = 0;
    while (i < nums.size()) {
      const int j = nums[i];
      if (j <= 0 || j >= nums.size()) {
        break;
      }
      if (j == nums[j]) {
        // Found duplicate
        return j;
      }
      std::swap(nums[i], nums[j]);
    }
    return 0;
  }
};

// Two pointers, time O(N), space O(1)
class Solution2 {
 public:
  int findDuplicate(std::vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[nums[0]];

    // Start first meet
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }

    // Start second meet
    fast = 0;
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }

    // The second meet point is the duplicate
    return slow;
  }
};

TEST(Solution, findDuplicate) {
  std::vector<std::pair<std::vector<int>, int>> cases = {
      std::make_pair(std::vector<int>{1, 3, 4, 2, 2}, 2),
      std::make_pair(std::vector<int>{3, 1, 3, 4, 2}, 3),
  };
  for (auto& c : cases) {
    auto c1 = c;
    auto c2 = c;
    EXPECT_EQ(Solution1().findDuplicate(c1.first), c1.second);
    EXPECT_EQ(Solution2().findDuplicate(c2.first), c2.second);
  }
}
