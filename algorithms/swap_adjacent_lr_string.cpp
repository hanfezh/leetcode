/*
 * =====================================================================================
 *
 *       Filename:  swap_adjacent_lr_string.cpp
 *
 *    Description:  777. Swap Adjacent in LR String
 *
 *        Version:  1.0
 *        Created:  11/08/2025 16:24:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <string>
#include <tuple>
#include <vector>

#include "gtest/gtest.h"

class Solution {
 public:
  bool canTransform(std::string start, std::string result) {
    const int n = start.length();
    if (n != result.length()) {
      return false;
    }

    int i = 0;
    int j = 0;
    while (i < n || j < n) {
      while (i < n && start[i] == 'X') {
        i++;
      }
      while (j < n && result[j] == 'X') {
        j++;
      }
      if (i == n && j == n) {
        return true;
      }
      if (i == n || j == n) {
        return false;
      }
      if (start[i] != result[j]) {
        return false;
      }
      if (start[i] == 'L' && i < j) {
        return false;
      }
      if (start[i] == 'R' && i > j) {
        return false;
      }
      i++;
      j++;
    }
    return (i == n && j == n);
  }
};

TEST(Solution, canTransform) {
  std::vector<std::tuple<std::string, std::string, bool>> cases = {
      {"RXXLRXRXL", "XRLXXRRLX", true},
      {"X", "L", false},
      {"LXXLXRLXXL", "XLLXRXLXLX", false},
      {"XXXRXXLXXXXXXXXRXXXR", "XXXXRLXXXXXXXXXXXXRR", true},
  };
  for (auto& [start, result, existed] : cases) {
    EXPECT_EQ(Solution().canTransform(start, result), existed);
  }
}
