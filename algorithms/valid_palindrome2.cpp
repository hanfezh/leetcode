/*
 * =====================================================================================
 *
 *       Filename:  valid_palindrome2.cpp
 *
 *    Description:  680. Valid Palindrome II. Given a non-empty string s, you
 * may delete at most one character. Judge whether you can make it a palindrome.
 *
 *        Version:  1.0
 *        Created:  04/08/19 11:48:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
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
  bool validPalindrome(const string& s) {
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
      if (s.at(i) != s.at(j)) {
        return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
      }
      i++;
      j--;
    }
    return true;
  }

 private:
  bool isPalindrome(const string& s, int i, int j) {
    while (i < j) {
      if (s.at(i++) != s.at(j--)) {
        return false;
      }
    }
    return true;
  }
};

TEST(Solution, validPalindrome) {
  vector<std::pair<string, bool>> cases = {
      std::make_pair(string("abc"), false),
      std::make_pair(string("abca"), true),
      std::make_pair(string("aabaca"), true),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().validPalindrome(c.first), c.second);
  }
}
