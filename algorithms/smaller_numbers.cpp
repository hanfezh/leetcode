/*
 * =====================================================================================
 *
 *       Filename:  smaller_numbers.cpp
 *
 *    Description:  1365. How Many Numbers Are Smaller Than the Current Number.
 *
 *        Version:  1.0
 *        Created:  02/19/2024 13:42:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <algorithm>
#include <map>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::map;
using std::vector;

class Solution {
 public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    if (nums.size() == 0) {
      return vector<int>{};
    }

    vector<int> copy(nums);
    std::sort(copy.begin(), copy.end());
    map<int, int> counts;
    for (int i = copy.size() - 1; i >= 0; i--) {
      counts[copy[i]] = i;
    }

    vector<int> results(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      results[i] = counts[nums[i]];
    }
    return results;
  }
};

TEST(Solution, smallerNumbersThanCurrent) {
  vector<std::pair<vector<int>, vector<int>>> cases = {
      std::make_pair(vector<int>{8, 1, 2, 2, 3}, vector<int>{4, 0, 1, 1, 3}),
      std::make_pair(vector<int>{6, 5, 4, 8}, vector<int>{2, 1, 0, 3}),
      std::make_pair(vector<int>{7, 7, 7, 7}, vector<int>{0, 0, 0, 0}),
  };
  for (auto& c : cases) {
    EXPECT_THAT(Solution().smallerNumbersThanCurrent(c.first), testing::ElementsAreArray(c.second));
  }
}
