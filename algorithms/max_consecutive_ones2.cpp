// 487. Max Consecutive Ones II
// Refer: https://leetcode.com/problems/max-consecutive-ones-ii
// Author: xianfeng.zhu@gmail.com

#include <algorithm>
#include <cstdio>
#include <vector>

// Keep last number of consective ones
class Solution1 {
 public:
  int findMaxConsecutiveOnes(std::vector<int>& nums) {
    int max_num = 0;
    int prev_num = 0;
    int curr_num = 0;
    for (const int val : nums) {
      curr_num++;
      if (val == 0) {
        prev_num = curr_num;
        curr_num = 0;
      }
      max_num = std::max(max_num, prev_num + curr_num);
    }
    return max_num;
  }
};

// Sliding window, two pointers
class Solution2 {
 public:
  int findMaxConsecutiveOnes(std::vector<int>& nums) {
    int max_num = 0;
    int last_zero_idx = -1;
    int cur_zero_num = 0;
    int left = -1;
    int right = -1;
    for (right = 0; right < nums.size(); right++) {
      if (nums[right] == 0) {
        cur_zero_num++;
        if (cur_zero_num > 1) {
          left = last_zero_idx;
          cur_zero_num--;
        }
        last_zero_idx = right;
      }
      max_num = std::max(max_num, right - left);
    }
    return max_num;
  }
};

using Solution = Solution2;

int main(int argc, char* argv[]) {
  std::vector<int> nums = {1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0};
  const int max_num = Solution().findMaxConsecutiveOnes(nums);
  printf("Max consecutive ones is %d\n", max_num);
  return 0;
}
