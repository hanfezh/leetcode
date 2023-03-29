/*
 * =====================================================================================
 *
 *       Filename:  three_sum.cpp
 *
 *    Description:  15. 3Sum. https://leetcode.com/problems/3sum/
 *
 *        Version:  1.0
 *        Created:  03/29/23 09:55:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <algorithm>
#include <set>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::set;
using std::vector;

// Sorting + Two Pointers
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    set<vector<int>> triplets;
    const int size = nums.size();
    for (int i = 0; i < size - 2; i++) {
      int l = i + 1;
      int r = size - 1;
      while (l < r) {
        const int sum = nums[i] + nums[l] + nums[r];
        if (sum == 0) {
          triplets.insert(vector<int>{nums[i], nums[l++], nums[r--]});
        } else if (sum < 0) {
          l++;
        } else {
          r--;
        }
      }
    }
    return vector<vector<int>>(triplets.begin(), triplets.end());
  }
};

TEST(Solution, threeSum) {
  vector<std::pair<vector<int>, vector<vector<int>>>> cases = {
      std::make_pair(vector<int>{0, 1, 1}, vector<vector<int>>{}),
      std::make_pair(vector<int>{0, 0, 0}, vector<vector<int>>{{0, 0, 0}}),
      std::make_pair(vector<int>{-1, 0, 1, 2, -1, -4},
                     vector<vector<int>>{{-1, -1, 2}, {-1, 0, 1}}),
  };
  for (auto& c : cases) {
    EXPECT_THAT(Solution().threeSum(c.first), testing::ElementsAreArray(c.second));
  }
}
