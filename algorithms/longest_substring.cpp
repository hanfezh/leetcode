/*
 * =====================================================================================
 *
 *       Filename:  longest_substring.cpp
 *
 *    Description:  3. Longest Substring Without Repeating Characters.
 *
 *        Version:  1.0
 *        Created:  01/29/2023 12:14:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <algorithm>
#include <cstdio>
#include <string>

using std::string;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int len = 0;
    int left = 0;
    for (int i = 0; i < s.size(); i++) {
      size_t p = s.find(s[i], left);
      if (p == string::npos || p >= i) {
        len = std::max(len, i - left + 1);
      } else {
        len = std::max(len, i - left);
        left = static_cast<int>(p + 1);
      }
    }
    return len;
  }
};

int main(int argc, char* argv[]) {
  string s = "abcabcbb";
  if (argc > 1) {
    s = argv[1];
  }
  const int len = Solution().lengthOfLongestSubstring(s);
  printf("Length of longest substring: %d\n", len);
  return 0;
}
