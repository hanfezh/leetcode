// 5. Longest Palindromic Substring
// Refer: https://leetcode.com/problems/longest-palindromic-substring
// Author: xianfeng.zhu@gmail.com

#include <cstdio>
#include <algorithm>
#include <string>

class Solution {
 public:
  std::string longestPalindrome(const std::string& s) {
    if (s.empty()) {
      return "";
    }

    int start = 0; 
    int end = 0;
    for (int i = 0; i < s.size(); i++) {
      const int len1 = expandAroundCenter(s, i, i);
      const int len2 = expandAroundCenter(s, i, i + 1);
      const int max_len = std::max(len1, len2);
      if (max_len > (end - start + 1)) {
        start = i - (max_len - 1)/ 2;
        end = i + max_len / 2;
      }
    }
    return s.substr(start, end - start + 1);
  }

 private:
  // Return the length of palindrome
  int expandAroundCenter(const std::string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      left--;
      right++;
    }
    return (right - left - 1);
  }
};

int main(int argc, char* argv[]) {
  std::string s = "aba";
  if (argc > 1) {
    s = argv[1];
  }
  std::string pa = Solution().longestPalindrome(s);
  printf("%s => %s\n", s.c_str(), pa.c_str());
  return 0;
}
