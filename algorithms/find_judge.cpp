/*
 * =====================================================================================
 *
 *       Filename:  find_judge.cpp
 *
 *    Description:  997. Find the Town Judge
 *                  https://leetcode.com/problems/find-the-town-judge/
 *
 *        Version:  1.0
 *        Created:  07/20/2024 21:50:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <tuple>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::tuple;
using std::vector;

class Solution {
 public:
  int findJudge(int n, vector<vector<int>>& trust) {
    if (trust.size() < n - 1) {
      return -1;
    }
    vector<int> indegrees(n + 1);
    vector<int> outdegrees(n + 1);
    for (const auto& t : trust) {
      indegrees[t[1]]++;
      outdegrees[t[0]]++;
    }
    for (int i = 1; i <= n; i++) {
      if (indegrees[i] == (n - 1) && outdegrees[i] == 0) {
        return i;
      }
    }
    return -1;
  }
};

TEST(Solution, findJudge) {
  vector<tuple<int, vector<vector<int>>, int>> cases = {
      std::make_tuple(2, vector<vector<int>>{{1, 2}}, 2),
      std::make_tuple(3, vector<vector<int>>{{1, 3}, {2, 3}}, 3),
      std::make_tuple(3, vector<vector<int>>{{1, 3}, {2, 3}, {3, 1}}, -1),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().findJudge(std::get<0>(c), std::get<1>(c)), std::get<2>(c));
  }
}
