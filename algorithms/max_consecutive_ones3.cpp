// 10004. Max Consecutive Ones III
// Refer: https://leetcode.com/problems/max-consecutive-ones-iii
// Author: xianfeng.zhu@gmail.com

#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

// Sliding window, two pointers
class Solution {
 public:
  int longestOnes(std::vector<int>& nums, int k) {
    std::queue<int> zero_indexes;
    int max_num = 0;
    int left = -1;
    int right = -1;
    for (right = 0; right < nums.size(); right++) {
      if (nums[right] == 0) {
        zero_indexes.push(right);
        if (zero_indexes.size() > k) {
          left = zero_indexes.front();
          zero_indexes.pop();
        }
      }
      max_num = std::max(max_num, right - left);
    }
    return max_num;
  }
};

int main(int argc, char* argv[]) {
  std::vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
  const int k = 2;
  const int max_num = Solution().longestOnes(nums, k);
  printf("Max consecutive ones is %d\n", max_num);
  return 0;
}
