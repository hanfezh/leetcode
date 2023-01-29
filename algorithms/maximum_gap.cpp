/*
 * =====================================================================================
 *
 *       Filename:  maximum_gap.cpp
 *
 *    Description:  164. Maximum Gap.
 *                  https://leetcode.com/problems/maximum-gap/description/
 *
 *        Version:  1.0
 *        Created:  01/28/2023 23:24:21
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
  int maximumGap(vector<int>& nums) {
    if (nums.size() < 2) {
      return 0;
    }

    int hi = INT_MIN;
    int lo = INT_MAX;
    for (const int n : nums) {
      hi = std::max(hi, n);
      lo = std::min(lo, n);
    }

    const int bsize = std::max(static_cast<int>((hi - lo) / (nums.size() - 1)), 1);
    vector<vector<int>> buckets((hi - lo) / bsize + 1, vector<int>());
    for (const int n : nums) {
      buckets[(n - lo) / bsize].push_back(n);
    }

    int gap = 0;
    int prev_hi = 0;
    for (const auto& bkt : buckets) {
      if (bkt.empty()) {
        continue;
      }

      int curr_hi = INT_MIN;
      int curr_lo = INT_MAX;
      for (const int n : bkt) {
        curr_hi = std::max(curr_hi, n);
        curr_lo = std::min(curr_lo, n);
      }
      if (prev_hi != 0) {
        gap = std::max(gap, curr_lo - prev_hi);
      } else {
        gap = std::max(gap, curr_hi - curr_lo);
      }
      prev_hi = curr_hi;
    }

    return gap;
  }
};

int main(int argc, char* argv[]) {
  vector<int> nums{3, 6, 9, 1};
  const int gap = Solution().maximumGap(nums);
  printf("Maximum gap: %d\n", gap);
  return 0;
}
