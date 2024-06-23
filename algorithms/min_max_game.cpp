/*
 * =====================================================================================
 *
 *       Filename:  min_max_game.cpp
 *
 *    Description:  2293. Min Max Game. https://leetcode.com/problems/min-max-game/
 *
 *        Version:  1.0
 *        Created:  06/23/2024 17:18:13
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

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::vector;

class Solution {
 public:
  int minMaxGame(vector<int>& nums) {
    int size = nums.size();
    if (size <= 1) {
      return (size == 0 ? 0 : nums[0]);
    }

    size /= 2;
    for (int i = 0; i < size; i++) {
      if ((i & 0x01) == 0) {
        nums[i] = std::min(nums[2 * i], nums[2 * i + 1]);
      } else {
        nums[i] = std::max(nums[2 * i], nums[2 * i + 1]);
      }
    }
    nums.resize(size);
    return minMaxGame(nums);
  }
};

TEST(Solution, minMaxGame) {
  vector<std::pair<vector<int>, int>> cases = {
      std::make_pair(vector<int>{1, 3, 5, 2, 4, 8, 2, 2}, 1),
      std::make_pair(vector<int>{3}, 3),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().minMaxGame(c.first), c.second);
  }
}
