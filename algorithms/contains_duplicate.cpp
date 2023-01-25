/*
 * =====================================================================================
 *
 *       Filename:  contains_duplicate.cpp
 *
 *    Description:  217. Contains Duplicate. Given an array of integers, find if the
 *                  array contains any duplicates.
 *
 *        Version:  1.0
 *        Created:  02/26/19 03:20:22
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
#include <set>
#include <vector>

// Quick sort
class Solution1 {
 public:
  bool containsDuplicate(std::vector<int>& nums) {
    bool is_dup = false;
    quickSort(nums, 0, nums.size() - 1, is_dup);
    return is_dup;
  }

 private:
  void quickSort(std::vector<int>& nums, int left, int right, bool& is_dup) {
    if (!is_dup && left < right) {
      int middle = partition(nums, left, right, is_dup);
      quickSort(nums, left, middle - 1, is_dup);
      quickSort(nums, middle + 1, right, is_dup);
    }
  }

  int partition(std::vector<int>& nums, int left, int right, bool& is_dup) {
    int midval = nums[right];
    int last = left;
    for (int i = left; i < right; i++) {
      if (nums[i] > midval) {
        continue;
      }
      if (nums[i] == midval) {
        // Stop partition
        is_dup = true;
        return last;
      }
      if (last != i) {
        swap(&nums[last], &nums[i]);
      }
      last++;
    }
    if (last != right) {
      swap(&nums[last], &nums[right]);
    }
    return last;
  }

  void swap(int* a, int* b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
  }
};

// std::sort
class Solution2 {
 public:
  bool containsDuplicate(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    for (size_t i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1]) {
        return true;
      }
    }
    return false;
  }
};

// Hash table
class Solution3 {
 public:
  bool containsDuplicate(std::vector<int>& nums) {
    return nums.size() > std::set<int>(nums.begin(), nums.end()).size();
  }
};

using Solution = Solution1;

int main(int argc, char* argv[]) {
  std::vector<int> nums = {10, 7, 8, 9, 1, 5, 1};
  if (argc > 2) {
    nums.clear();
    for (int i = 1; i < argc; i++) {
      nums.push_back(atoi(argv[i]));
    }
  }
  auto is_dup = Solution().containsDuplicate(nums);
  printf("Contains duplicate? %s\n", (is_dup ? "Yes" : "No"));
  return 0;
}
