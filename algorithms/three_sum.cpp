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
class Solution1 {
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

// Sorting + Two Pointers, without std::set
class Solution2 {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> triplets;
    const int size = nums.size();
    for (int i = 0; i < size - 2; i++) {
      int l = i + 1;
      int r = size - 1;
      while (l < r) {
        const int sum = nums[i] + nums[l] + nums[r];
        if (sum == 0) {
          vector<int> t{nums[i], nums[l++], nums[r--]};
          while (l < r && nums[l] == t[1]) {
            l++;
          }
          while (l < r && nums[r] == t[2]) {
            r--;
          }
          triplets.push_back(std::move(t));
        } else if (sum < 0) {
          l++;
        } else {
          r--;
        }
      }
      while ((i + 1) < size && nums[i] == nums[i + 1]) {
        i++;  // Ignore duplicated number
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
    auto c1 = c;
    auto c2 = c;
    EXPECT_THAT(Solution1().threeSum(c1.first), testing::ElementsAreArray(c1.second));
    EXPECT_THAT(Solution2().threeSum(c2.first), testing::ElementsAreArray(c2.second));
  }
}
