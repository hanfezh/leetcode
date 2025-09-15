/*
 * =====================================================================================
 *
 *       Filename:  is_subsequence.cpp
 *
 *    Description: 392. Is Subsequence https://leetcode.com/problems/is-subsequence/
 *
 *        Version:  1.0
 *        Created:  03/03/2022 10:39:12
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

class Solution1 {
 public:
  bool isSubsequence(std::string s, std::string t) {
    int i = 0;
    int j = s.size() - 1;
    int l = 0;
    int r = t.size() - 1;
    while ((i <= j) && (r - l >= j - i)) {
      if (s[i] == t[l]) {
        i++;
      }
      if (s[j] == t[r]) {
        j--;
      }
      l++;
      r--;
    }
    return (i > j);
  }
};

class Solution2 {
 public:
  bool isSubsequence(std::string s, std::string t) {
    int i = 0;
    int j = 0;
    while (j < t.length()) {
      if (i < s.length() && s[i] == t[j]) {
        i++;
      }
      if (i == s.length()) {
        break;
      }
      j++;
    }
    return (i == s.length());
  }
};

TEST(Solution, isSubsequence) {
  std::vector<std::tuple<std::string, std::string, bool>> cases = {
      {"abc", "ahbgdc", true}, {"axc", "ahbgdc", false}, {"", "ahbgdc", true},
      {"", "", true},          {"aza", "abzba", true},
  };
  for (auto& [s, t, ret] : cases) {
    EXPECT_EQ(Solution1().isSubsequence(s, t), ret);
    EXPECT_EQ(Solution2().isSubsequence(s, t), ret);
  }
}
