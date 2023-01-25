/*
 * =====================================================================================
 *
 *       Filename:  assign_cookies.cpp
 *
 *    Description:  455. Assign Cookies. https://leetcode.com/problems/assign-cookies/
 *
 *        Version:  1.0
 *        Created:  01/25/2023 21:57:11
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
#include <vector>

using std::vector;

class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    int i = 0;
    int j = 0;

    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());

    while (i < g.size() && j < s.size()) {
      if (s[j] >= g[i]) {
        i++;
      }
      j++;
    }
    return i;
  }
};

int main(int argc, char* argv[]) {
  vector<int> g({1, 2, 3});
  vector<int> s({1, 1});
  const int n = Solution().findContentChildren(g, s);
  printf("Maximize number of children: %d\n", n);
  return 0;
}
