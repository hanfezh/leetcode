// =====================================================================================
//
//       Filename:  majority_element.cpp
//
//    Description:  169. Majority Element.
//
//        Version:  1.0
//        Created:  09/19/2019 08:39:09 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:
//
// =====================================================================================
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

// Sort
class Solution1 {
 public:
  int majorityElement(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
  }
};

// Hash table
class Solution2 {
 public:
  int majorityElement(std::vector<int>& nums) {
    std::unordered_map<int, int> counts;
    for (int n : nums) {
      counts[n]++;
    }
    for (auto& c : counts) {
      if (c.second > (nums.size() / 2)) {
        return c.first;
      }
    }
    return 0;
  }
};

// Boyer–Moore majority vote
class Solution3 {
 public:
  int majorityElement(std::vector<int>& nums) {
    int i = 0;
    int m = 0;
    for (auto x : nums) {
      if (i == 0) {
        m = x;
        i = 1;
      } else if (x == m) {
        i++;
      } else {
        i--;
      }
    }

    return m;
  }
};

TEST(Solution, majorityElement) {
  std::vector<std::pair<std::vector<int>, int>> cases = {
      std::make_pair(std::vector<int>{3, 2, 3}, 3),
      std::make_pair(std::vector<int>{2, 2, 1, 1, 1, 2, 2}, 2),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution1().majorityElement(c.first), c.second);
    EXPECT_EQ(Solution2().majorityElement(c.first), c.second);
    EXPECT_EQ(Solution3().majorityElement(c.first), c.second);
  }
}
