// 485. Max Consecutive Ones
// Refer: https://leetcode.com/problems/max-consecutive-ones
// Author: xianfeng.zhu@gmail.com

#include <cstdio>
#include <algorithm>
#include <vector>

class Solution {
 public:
  int findMaxConsecutiveOnes(std::vector<int>& nums) {
    int max_num = 0;
    int last_idx = 0;
    int i = 0;
    while (i < nums.size()) {
      if (nums[i] == 0) {
        max_num = std::max(max_num, i - last_idx);
        last_idx = i + 1;
      }
      i++;
    }
    return std::max(max_num, i - last_idx);
  }
};

int main(int argc, char* argv[]) {
  std::vector<int> nums = {1, 1, 0, 1, 1, 1};
  const int max_num = Solution().findMaxConsecutiveOnes(nums);
  printf("The maximum number of consecutive 1s is %d\n", max_num);
  return 0;
}
