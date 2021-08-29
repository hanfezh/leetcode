// 215. Kth Largest Element in an Array
// URL: https://leetcode.com/problems/kth-largest-element-in-an-array
// Author: xianfeng.zhu@gmail.com

#include <cstdio>
#include <vector>

// Partition and sort
class Solution {
 public:
  int findKthLargest(std::vector<int>& nums, int k) {
    int left = 0;
    int right = nums.size() - 1;
    k = nums.size() - k;
    while (true) {
      const int idx = partition(nums, left, right);
      if (idx < k) {
        left = idx + 1;
      } else if (idx > k) {
        right = idx - 1;
      } else {
        break;
      }
    }
    return nums[k];
  }

 private:
  int partition(std::vector<int>& nums, int left, int right) {
    const int pivot = right;
    while (left < right) {
      if (nums[left] < nums[pivot]) {
        left++;
      } else if (nums[right] >= nums[pivot]) {
        right--;
      } else {
        std::swap(nums[left], nums[right]);
      }
    }
    std::swap(nums[pivot], nums[left]);
    return left;
  }
};

int main(int argc, char* argv[]) {
  std::vector<int> nums = {3, 2, 1, 5, 6, 4};
  const int k = 2;
  const int kth = Solution().findKthLargest(nums, k);
  printf("Kth largest is %d\n", kth);
  return 0;
}
