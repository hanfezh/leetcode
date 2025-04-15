/*
 * =====================================================================================
 *
 *       Filename:  largest_divisible_subset.cpp
 *
 *    Description:  368. Largest Divisible Subset
 *                  https://leetcode.com/problems/largest-divisible-subset/
 *
 *        Version:  1.0
 *        Created:  04/15/2025 12:13:06
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

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::vector;

// Dynamic programming
class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    bool flag = true;
    if (nums.front() != 1) {
      nums.insert(nums.begin(), 1);
      flag = false;
    }

    vector<std::pair<int, int>> dp(nums.size());
    for (int i = nums.size() - 1; i >= 0; i--) {
      dp[i].first = 0;
      dp[i].second = i;
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[j] % nums[i] == 0) {
          if (dp[j].first > dp[i].first) {
            dp[i].first = dp[j].first;
            dp[i].second = j;
          }
        }
      }
      dp[i].first++;
    }

    vector<int> subset;
    int i = 0;
    subset.push_back(nums[i]);
    while (dp[i].second != i) {
      i = dp[i].second;
      subset.push_back(nums[i]);
    }
    if (!flag) {
      subset.erase(subset.begin());
    }
    return subset;
  }
};

TEST(Solution, largestDivisibleSubset) {
  vector<std::pair<vector<int>, vector<int>>> cases = {
      std::make_pair(vector<int>{1, 2, 3}, vector<int>{1, 2}),
      std::make_pair(vector<int>{1, 2, 4, 8}, vector<int>{1, 2, 4, 8}),
  };
  for (auto& c : cases) {
    EXPECT_THAT(Solution().largestDivisibleSubset(c.first), testing::ElementsAreArray(c.second));
  }
}
