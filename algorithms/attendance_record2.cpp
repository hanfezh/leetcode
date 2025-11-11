/*
 * =====================================================================================
 *
 *       Filename:  attendance_record2.cpp
 *
 *    Description:  552. Student Attendance Record II
 *
 *        Version:  1.0
 *        Created:  11/11/2025 23:52:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <cmath>
#include <utility>
#include <vector>

#include "gtest/gtest.h"

class Solution {
 public:
  int checkRecord(int n) {
    const int m = static_cast<int>(std::pow(10.0, 9)) + 7;

    // Initial map if n = 1
    //   - - - - - - -
    //   |   L 0 1 2 |
    //   | A - - - - -
    //   | 0 | 1 1 0 |
    //   | 1 | 1 0 0 |
    //   | - - - - - |
    std::vector<std::vector<int64_t>> res = {
        {1, 1, 0},
        {1, 0, 0},
    };

    for (int i = 1; i < n; i++) {
      std::vector<std::vector<int64_t>> tmp(2, std::vector<int64_t>(3, 0));

      // Append A
      tmp[1][0] = (res[0][0] + res[0][1] + res[0][2]) % m;

      // Append L
      tmp[0][1] = res[0][0];
      tmp[0][2] = res[0][1];
      tmp[1][1] = res[1][0];
      tmp[1][2] = res[1][1];

      // Append P
      tmp[0][0] = (res[0][0] + res[0][1] + res[0][2]) % m;
      tmp[1][0] = (tmp[1][0] + res[1][0] + res[1][1] + res[1][2]) % m;

      res.swap(tmp);
    }

    int64_t total = 0;
    for (const auto& r : res) {
      for (const auto& v : r) {
        total += v;
      }
    }
    return total % m;
  }
};

TEST(Solution, checkRecord) {
  std::vector<std::pair<int, int>> cases = {
      {1, 3},
      {2, 8},
      {10101, 183236316},
  };
  for (auto& [n, res] : cases) {
    EXPECT_EQ(Solution().checkRecord(n), res);
  }
}
