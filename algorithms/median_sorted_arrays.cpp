// =====================================================================================
//
//       Filename:  median_sorted_arrays.cpp
//
//    Description:  4. Median of Two Sorted Arrays.
//
//        Version:  1.0
//        Created:  11/11/2019 08:14:01 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:
//
// =====================================================================================
#include <tuple>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::tuple;
using std::vector;

// Intuitive: O(m+n)
class Solution1 {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    const int m = (nums1.size() + nums2.size() - 1) / 2;
    const int n = (nums1.size() + nums2.size()) / 2;
    int steps = 0;
    double median = 0.0;

    auto apply = [&](int val) {
      if (steps == m) {
        median = val;
      }
      if (steps == n) {
        median = (median + val) / 2.0;
        return true;
      }
      return false;
    };

    bool ok = false;
    for (int i = 0, j = 0;; steps++) {
      if (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
          ok = apply(nums1[i]);
          i++;
        } else {
          ok = apply(nums2[j]);
          j++;
        }
      } else if (i < nums1.size()) {
        ok = apply(nums1[i]);
        i++;
      } else {
        ok = apply(nums2[j]);
        j++;
      }
      if (ok) {
        break;
      }
    }
    return median;
  }
};

// Binary search, O(log(m))
class Solution2 {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    const int m = nums1.size();
    const int n = nums2.size();
    if (m > n) {
      // Ensure m <= n
      return findMedianSortedArrays(nums2, nums1);
    }

    const int half = (m + n + 1) / 2;
    int l = 0;
    int r = m;

    while (l <= r) {
      const int i = (l + r) / 2;  // Index in nums1
      const int j = half - i;     // Index in nums2
      const int left1 = (i > 0 ? nums1[i - 1] : INT_MIN);
      const int right1 = (i < m ? nums1[i] : INT_MAX);
      const int left2 = (j > 0 ? nums2[j - 1] : INT_MIN);
      const int right2 = (j < n ? nums2[j] : INT_MAX);
      if ((left1 <= right2) && (left2 <= right1)) {
        if ((m + n) & 0x1) {  // Odd
          return std::max(left1, left2);
        } else {  // Even
          return (std::max(left1, left2) + std::min(right1, right2)) / 2.0;
        }
      } else if (left1 > right2) {
        r = i - 1;
      } else {
        l = i + 1;
      }
    }
    return 0.0;
  }
};

TEST(Solution, findMedianSortedArrays) {
  vector<tuple<vector<int>, vector<int>, double>> cases = {
      std::make_tuple(vector<int>{}, vector<int>{2}, 2.0),
      std::make_tuple(vector<int>{1, 3}, vector<int>{2}, 2.0),
      std::make_tuple(vector<int>{1, 2}, vector<int>{3, 4}, 2.5),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution1().findMedianSortedArrays(std::get<0>(c), std::get<1>(c)), std::get<2>(c));
    EXPECT_EQ(Solution2().findMedianSortedArrays(std::get<0>(c), std::get<1>(c)), std::get<2>(c));
  }
}
