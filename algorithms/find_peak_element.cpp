// =====================================================================================
//
//       Filename:  find_peak_element.cpp
//
//    Description:  162. Find Peak Element.
//
//        Version:  1.0
//        Created:  09/12/2019 09:59:46 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:
//
// =====================================================================================
#include <vector>

#include "gtest/gtest.h"

using namespace std;

// Time complexity: O(logn)
// Constraints:
//   nums[i] != nums[i + 1]
class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    const int n = nums.size();
    int l = 0, r = n - 1, m = -1;
    while (l <= r) {
      m = l + (r - l) / 2;
      if (m > 0 && nums[m] < nums[m - 1]) {
        r = m - 1;
      } else if (m < n - 1 && nums[m] < nums[m + 1]) {
        l = m + 1;
      } else {
        return m;
      }
    }
    return -1;
  }
};

TEST(Solution, findPeakElement) {
  vector<vector<int>> cases = {
      {1, 2, 3, 1},
      {1, 2, 1, 3, 5, 6, 4},
  };
  for (auto& nums : cases) {
    int i = Solution().findPeakElement(nums);
    EXPECT_TRUE(i == 0 || (i > 0 && nums[i] > nums[i - 1]));
    EXPECT_TRUE(i == nums.size() - 1 || (i < nums.size() - 1 && nums[i] > nums[i + 1]));
  }
}
