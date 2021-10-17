/*
 * =====================================================================================
 *
 *       Filename:  maximum_subarray.cpp
 *
 *    Description:  Maximum Subarray: Given an integer array nums, find the contiguous
 *                  subarray (containing at least one number) which has the largest sum
 *                  and return its sum.
 *
 *        Version:  1.0
 *        Created:  09/04/18 08:07:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <vector>

class Solution {
 public:
  int maxSubArray(const std::vector<int>& nums) {
    int max_sum = INT_MIN;
    int last_sum = 0;
    for (const int val : nums) {
      last_sum += val;
      if (max_sum < last_sum) {
        max_sum = last_sum;
      }
      if (last_sum < 0) {
        last_sum = 0;
      }
    }

    return max_sum;
  }
};

int main(int argc, char* argv[]) {
  std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  if (argc > 3) {
    nums.clear();
    for (int i = 1; i < argc; i++) {
      nums.push_back(atoi(argv[i]));
    }
  }

  int max = Solution().maxSubArray(nums);
  printf("%d\n", max);

  return 0;
}
