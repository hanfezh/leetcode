/*
 * =====================================================================================
 *
 *       Filename:  longest_palindrome.cpp
 *
 *    Description:  409. Longest Palindrome.
 *                  https://leetcode.com/problems/longest-palindrome/
 *
 *        Version:  1.0
 *        Created:  02/16/2023 15:19:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <array>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::array;
using std::string;

class Solution {
 public:
  int longestPalindrome(string s) {
    array<int, 54> counts = {0};
    for (char c : s) {
      if (c >= 'A' && c <= 'Z') {
        counts[c - 'A']++;
      } else if (c >= 'a' && c <= 'z') {
        counts[c - 'a' + 26]++;
      }
    }

    int len = 0;
    bool odd = false;
    for (int c : counts) {
      len += c & (~0x01);
      if ((c & 0x01) != 0) {
        odd = true;
      }
    }
    if (odd) {
      len++;
    }
    return len;
  }
};

TEST(Solution, longestPalindrome) {
  std::vector<std::pair<string, int>> cases = {
      std::make_pair(string("a"), 1),
      std::make_pair(string("ccc"), 3),
      std::make_pair(string("abccccdd"), 7),
      std::make_pair(string("aaaAaaaa"), 7),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().longestPalindrome(c.first), c.second);
  }
}
