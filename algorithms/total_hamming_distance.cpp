// 477. Total Hamming Distance
// Refer: https://leetcode.com/problems/total-hamming-distance/
// Author: xianfeng.zhu@gmail.com

#include <cstdio>
#include <vector>

class Solution {
 public:
  int totalHammingDistance(std::vector<int>& nums) {
    int sum = 0;
    for (int i = 0; i < 32; i++) {
      int count = 0;
      for (const int val : nums) {
        count += ((val >> i) & 0x1);
      }
      sum += count * (nums.size() - count);
    }
    return sum;
  }
};

int main(int argc, char* argv[]) {
  std::vector<int> nums = {4, 14, 2};
  int sum = Solution().totalHammingDistance(nums);
  printf("total distance is %d\n", sum);
  return 0;
}
