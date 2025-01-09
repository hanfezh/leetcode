/*
 * =====================================================================================
 *
 *       Filename:  shifting_letters2.cpp
 *
 *    Description:  2381. Shifting Letters II
 *                  https://leetcode.com/problems/shifting-letters-ii/
 *
 *        Version:  1.0
 *        Created:  01/09/2025 21:14:02
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

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::string;
using std::tuple;
using std::vector;

// Difference array
class Solution {
 public:
  string shiftingLetters(string s, vector<vector<int>>& shifts) {
    const int kIncrement = 1;
    const int kDecrement = 0;
    const int size = s.length();

    vector<int> diffs(size, 0);
    for (const auto& sh : shifts) {
      if (sh[2] == kIncrement) {
        diffs[sh[0]]++;
        if ((sh[1] + 1) < size) {
          diffs[sh[1] + 1]--;
        }
      } else if (sh[2] == kDecrement) {
        diffs[sh[0]]--;
        if ((sh[1] + 1) < size) {
          diffs[sh[1] + 1]++;
        }
      }
    }

    int cnt = 0;
    for (int i = 0; i < size; i++) {
      cnt = (cnt + diffs[i]) % 26;
      if (cnt < 0) {
        cnt += 26;
      }
      s[i] = (s[i] - 'a' + cnt) % 26 + 'a';
    }
    return s;
  }
};

TEST(Solution, shiftingLetters) {
  vector<tuple<string, vector<vector<int>>, string>> cases = {
      std::make_tuple("abc", vector<vector<int>>{{0, 1, 0}, {1, 2, 1}, {0, 2, 1}}, "ace"),
      std::make_tuple("dztz", vector<vector<int>>{{0, 0, 0}, {1, 1, 1}}, "catz"),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().shiftingLetters(std::get<0>(c), std::get<1>(c)), std::get<2>(c));
  }
}
