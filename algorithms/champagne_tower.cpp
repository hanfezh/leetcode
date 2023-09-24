/*
 * =====================================================================================
 *
 *       Filename:  champagne_tower.cpp
 *
 *    Description:  799. Champagne Tower.
 *
 *        Version:  1.0
 *        Created:  09/24/2023 15:11:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <algorithm>
#include <tuple>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::tuple;
using std::vector;

// Dynamic programming
class Solution {
 public:
  double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> flows(101, vector<double>(101));
    flows[0][0] = static_cast<double>(poured);
    for (int r = 0; r <= query_row; ++r) {
      for (int c = 0; c <= r; c++) {
        const double q = (flows[r][c] - 1.0) / 2.0;
        if (q > 0) {
          flows[r + 1][c] += q;
          flows[r + 1][c + 1] += q;
        }
      }
    }
    return std::min(1.0, flows[query_row][query_glass]);
  }
};

TEST(Solution, champagneTower) {
  vector<tuple<int, int, int, double>> cases = {
      std::make_tuple(1, 1, 1, 0.0),
      std::make_tuple(2, 1, 1, 0.5),
      std::make_tuple(100000009, 33, 17, 1.0),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().champagneTower(std::get<0>(c), std::get<1>(c), std::get<2>(c)),
              std::get<3>(c));
  }
}
