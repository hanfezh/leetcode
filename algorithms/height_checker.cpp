/*
 * =====================================================================================
 *
 *       Filename:  height_checker.cpp
 *
 *    Description:  1051. Height Checker
 *                  https://leetcode.com/problems/height-checker/description/
 *
 *        Version:  1.0
 *        Created:  01/24/2023 22:08:56
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
  int heightChecker(vector<int>& heights) {
    int num = 0;
    vector<int> copy(heights.begin(), heights.end());
    std::sort(copy.begin(), copy.end());
    for (int i = 0; i < heights.size(); i++) {
      if (heights[i] != copy[i]) {
        num += 1;
      }
    }
    return num;
  }
};

int main(int argc, char* argv[]) {
  vector<int> heights({1, 1, 4, 2, 1, 3});
  const int num = Solution().heightChecker(heights);
  printf("Number of indices: %d\n", num);
  return 0;
}
