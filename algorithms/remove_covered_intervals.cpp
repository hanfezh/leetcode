/*
 * =====================================================================================
 *
 *       Filename:  remove_covered_intervals.cpp
 *
 *    Description:  1288. Remove Covered Intervals
 *                  https://leetcode.com/problems/remove-covered-intervals/
 *
 *        Version:  1.0
 *        Created:  02/21/2022 11:04:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <algorithm>
#include <climits>
#include <vector>

class Solution {
 public:
  int removeCoveredIntervals(std::vector<std::vector<int>>& intervals) {
    int res = 0;
    int left = INT_MIN;
    int right = INT_MIN;
    std::sort(intervals.begin(), intervals.end());
    for (const std::vector<int>& cur : intervals) {
      // (l1, r1), (l2, r2), (l3, r3)
      // case 1: l1 == l2, overlapping
      // case 2: l1 < l2 && l1 > l2, overlapping
      // case 3: l1 < l2 && l1 < l2, not overlapping
      if (cur[0] > left && cur[1] > right) {
        left = cur[0];
        res++;
      }
      right = std::max(right, cur[1]);
    }
    return res;
  }
};

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> intervals = {{1, 4}, {3, 6}, {2, 8}};
  const int res = Solution().removeCoveredIntervals(intervals);
  printf("%d\n", res);
  return 0;
}
