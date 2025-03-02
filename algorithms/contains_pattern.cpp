/*
 * =====================================================================================
 *
 *       Filename:  contains_pattern.cpp
 *
 *    Description:  1566. Detect Pattern of Length M Repeated K or More Times
 *
 *        Version:  1.0
 *        Created:  03/01/2025 16:02:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <algorithm>
#include <tuple>
#include <vector>

#include "gtest/gtest.h"

class Solution {
 public:
  bool containsPattern(std::vector<int>& arr, int m, int k) {
    int cnt = 1;
    auto pre = arr.begin();
    auto cur = pre + m;
    while (cur + m <= arr.end()) {
      if (std::equal(pre, pre + m, cur)) {
        cnt++;
        if (cnt >= k) {
          return true;
        }
        cur += m;
      } else {
        pre++;
        cur = pre + m;
        cnt = 1;
      }
    }
    return false;
  }
};

TEST(Solution, containsPattern) {
  std::vector<std::tuple<std::vector<int>, int, int, bool>> cases = {
      std::make_tuple(std::vector<int>{1, 2, 4, 4, 4, 4}, 1, 3, true),
      std::make_tuple(std::vector<int>{1, 2, 1, 2, 1, 1, 1, 3}, 2, 2, true),
      std::make_tuple(std::vector<int>{1, 2, 1, 2, 1, 3}, 2, 3, false),
      std::make_tuple(std::vector<int>{2, 2}, 1, 2, true),
      std::make_tuple(std::vector<int>{3, 6, 6, 6, 5, 1, 5, 2, 2, 3, 1, 5, 2,
                                       6, 1, 5, 1, 2, 6, 3, 3, 5, 3, 6, 3, 4},
                      6, 2, false),
      std::make_tuple(std::vector<int>{3, 2, 2, 1, 2, 2, 1, 1, 1, 2, 3, 2, 2}, 3, 2, true),
      std::make_tuple(std::vector<int>{2, 2, 2, 2}, 2, 3, false),
      std::make_tuple(std::vector<int>{2, 2}, 1, 2, true),
      std::make_tuple(std::vector<int>{2, 1, 1, 2, 2, 1, 2, 2, 1, 2}, 1, 3, false),
  };
  for (auto& [arr, m, k, exst] : cases) {
    EXPECT_EQ(Solution().containsPattern(arr, m, k), exst);
  }
}
