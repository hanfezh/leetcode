// 912. Sort an Array
// Refer: https://leetcode.com/problems/sort-an-array
// Author: xianfeng.zhu@gmail.com

#include <cstdio>
#include <vector>

// Merge sort
class Solution {
 public:
  std::vector<int> sortArray(std::vector<int>& nums) {
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
  }

 private:
  void mergeSort(std::vector<int>& nums, int left, int right) {
    if (left >= right) {
      return;
    }

    int mid = (left + right) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    mergeArray(nums, left, mid, right);
  }

  void mergeArray(std::vector<int>& nums, int left, int mid, int right) {
    std::vector<int> buf(nums.begin() + left, nums.begin() + right + 1);
    mid -= left;
    right -= left;

    int i = 0;
    int j = mid + 1;
    int k = left;
    while (i <= mid && j <= right) {
      if (buf[i] < buf[j]) {
        nums[k++] = buf[i++];
      } else {
        nums[k++] = buf[j++];
      }
    }
    while (i <= mid) {
      nums[k++] = buf[i++];
    }
    while (j <= right) {
      nums[k++] = buf[j++];
    }
  }
};

int main(int argc, char* argv[]) {
  std::vector<int> nums = {5, 2, 3, 1};
  Solution().sortArray(nums);
  for (const int val : nums) {
    printf("%d ", val);
  }
  printf("\n");
  return 0;
}
