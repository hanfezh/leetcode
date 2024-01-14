/*
 * =====================================================================================
 *
 *       Filename:  h_index.cpp
 *
 *    Description:  274. H-Index. https://leetcode.com/problems/h-index/
 *
 *        Version:  1.0
 *        Created:  01/14/2024 10:49:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <algorithm>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::vector;

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    std::sort(citations.begin(), citations.end());
    auto it = citations.rbegin();
    int h = 0;
    while (it != citations.rend()) {
      if (*it++ <= h) {
        break;
      }
      h++;
    }
    return h;
  }
};

TEST(Solution, hIndex) {
  vector<std::pair<vector<int>, int>> cases = {
      std::make_pair(vector<int>{3, 0, 6, 1, 5}, 3),
      std::make_pair(vector<int>{1, 3, 1}, 1),
      std::make_pair(vector<int>{13, 15}, 2),
      std::make_pair(vector<int>{100}, 1),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().hIndex(c.first), c.second);
  }
}
