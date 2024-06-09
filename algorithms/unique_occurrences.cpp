/*
 * =====================================================================================
 *
 *       Filename:  unique_occurrences.cpp
 *
 *    Description:  1207. Unique Number of Occurrences
 *                  https://leetcode.com/problems/unique-number-of-occurrences/
 *
 *        Version:  1.0
 *        Created:  06/09/2024 09:57:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <map>
#include <set>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::map;
using std::pair;
using std::set;
using std::vector;

class Solution {
 public:
  bool uniqueOccurrences(vector<int>& arr) {
    map<int, int> counts;
    for (const int val : arr) {
      counts[val]++;
    }
    set<int> occ;
    for (const auto& entry : counts) {
      auto ret = occ.insert(entry.second);
      if (!ret.second) {
        return false;
      }
    }
    return true;
  }
};

TEST(Solution, uniqueOccurrences) {
  vector<pair<vector<int>, bool>> cases = {
      std::make_pair(vector<int>{1, 2}, false),
      std::make_pair(vector<int>{1, 2, 2, 1, 1, 3}, true),
      std::make_pair(vector<int>{-3, 0, 1, -3, 1, 1, 1, -3, 10, 0}, true),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().uniqueOccurrences(c.first), c.second);
  }
}
