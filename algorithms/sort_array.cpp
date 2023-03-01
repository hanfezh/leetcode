// 912. Sort an Array
// Refer: https://leetcode.com/problems/sort-an-array
// Author: xianfeng.zhu@gmail.com

#include <algorithm>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

// Merge sort
class Solution1 {
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

// Quick sort, time limit exceeded
class Solution2 {
 public:
  std::vector<int> sortArray(std::vector<int>& nums) {
    quickSort(nums, 0, nums.size() - 1);
    return nums;
  }

 private:
  void quickSort(std::vector<int>& nums, int left, int right) {
    if (left < right) {
      int pi = partition(nums, left, right);
      quickSort(nums, left, pi - 1);
      quickSort(nums, pi + 1, right);
    }
  }

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
    std::swap(nums[left], nums[pivot]);
    return left;
  }
};

TEST(Solution, sortArray) {
  std::vector<std::vector<int>> cases = {
      std::vector<int>{1},
      std::vector<int>{1, 2, 3},
      std::vector<int>{5, 2, 3, 1},
      std::vector<int>{5, 1, 1, 2, 0, 0},
  };
  for (auto& c : cases) {
    std::vector<int> nums = c;
    std::sort(nums.begin(), nums.end());

    std::vector<int> c1 = c;
    Solution1().sortArray(c1);
    EXPECT_THAT(c1, testing::ElementsAreArray(nums));

    std::vector<int> c2 = c;
    Solution2().sortArray(c2);
    EXPECT_THAT(c2, testing::ElementsAreArray(nums));
  }
}
