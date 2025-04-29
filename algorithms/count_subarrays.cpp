/*
 * =====================================================================================
 *
 *       Filename:  count_subarrays.cpp
 *
 *    Description:  3392. Count Subarrays of Length Three With a Condition
 *                  https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/
 *
 *        Version:  1.0
 *        Created:  04/29/2025 22:52:55
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

using std::vector;

class Solution {
 public:
  int countSubarrays(vector<int>& nums) {
    int count = 0;
    for (int i = 1; i < nums.size() - 1; i++) {
      if ((nums[i - 1] + nums[i + 1]) * 2 == nums[i]) {
        count++;
      }
    }
    return count;
  }
};

TEST(Solution, countSubarrays) {
  vector<std::pair<vector<int>, int>> cases = {
      std::make_pair(vector<int>{1, 2, 1, 4, 1}, 1),
      std::make_pair(vector<int>{1, 1, 1}, 0),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().countSubarrays(c.first), c.second);
  }
}
