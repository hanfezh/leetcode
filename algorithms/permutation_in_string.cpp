/*
 * =====================================================================================
 *
 *       Filename:  permutation_in_string.cpp
 *
 *    Description:  567. Permutation in String
 *                  https://leetcode.com/problems/permutation-in-string/
 *
 *        Version:  1.0
 *        Created:  02/11/2025 13:25:35
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

using std::string;

// Sorting
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length()) {
      return false;
    }
    std::sort(s1.begin(), s1.end());
    for (int i = 0; i <= s2.length() - s1.length(); i++) {
      string ss = s2.substr(i, s1.length());
      std::sort(ss.begin(), ss.end());
      if (ss == s1) {
        return true;
      }
    }
    return false;
  }
};

TEST(Solution, checkInclusion) {
  std::vector<std::tuple<string, string, bool>> cases = {
      std::make_tuple("ab", "eidbaooo", true),
      std::make_tuple("ab", "eidboaoo", false),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().checkInclusion(std::get<0>(c), std::get<1>(c)), std::get<2>(c));
  }
}
