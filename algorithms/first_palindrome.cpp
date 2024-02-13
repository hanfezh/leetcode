/*
 * =====================================================================================
 *
 *       Filename:  first_palindrome.cpp
 *
 *    Description:  2108. Find First Palindromic String in the Array.
 *
 *        Version:  1.0
 *        Created:  02/13/2024 16:27:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <string>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::string;
using std::vector;

// Two pointers
class Solution {
 public:
  string firstPalindrome(vector<string>& words) {
    for (const string& s : words) {
      if (isPalindrome(s)) {
        return s;
      }
    }
    return "";
  }

  bool isPalindrome(const string& s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
      if (s[i] != s[j]) {
        return false;
      }
    }
    return (s.size() > 0);
  }
};

TEST(Solution, firstPalindrome) {
  vector<std::pair<vector<string>, string>> cases = {
      std::make_pair(vector<string>{"abc", "car", "ada", "racecar", "cool"}, "ada"),
      std::make_pair(vector<string>{"notapalindrome", "racecar"}, "racecar"),
      std::make_pair(vector<string>{"def", "ghi"}, ""),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().firstPalindrome(c.first), c.second);
  }
}
