// 487. Max Consecutive Ones II
// Refer: https://leetcode.com/problems/max-consecutive-ones-ii
// Author: xianfeng.zhu@gmail.com

#include <algorithm>
#include <cstdio>
#include <vector>

class Solution {
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

int main(int argc, char* argv[]) {
  std::vector<int> nums = {1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0};
  const int max_num = Solution().findMaxConsecutiveOnes(nums);
  printf("Max consecutive ones is %d\n", max_num);
  return 0;
}
