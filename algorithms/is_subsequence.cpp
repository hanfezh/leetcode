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
#include <cstdio>
#include <string>

class Solution {
 public:
  bool isSubsequence(const std::string& s, const std::string& t) {
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

int main(int argc, char* argv[]) {
  std::string s = "abc";
  std::string t = "ahbgdc";
  if (argc > 2) {
    s = argv[1];
    t = argv[2];
  }
  const bool is_subseq = Solution().isSubsequence(s, t);
  printf("s = %s, t = %s\n", s.c_str(), t.c_str());
  printf("%s\n", (is_subseq ? "true" : "false"));
  return 0;
}
