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

// Binary search
class Solution1 {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }
    if (nums2.size() == 0) {
      return 0.0;
    }

    // Ensure m <= n
    int m = nums1.size();
    int n = nums2.size();
    int left = 0;
    int right = m;
    int i = 0;
    int j = 0;

    //       left_part          |        right_part
    // A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
    // B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]

    while (left <= right) {
      i = (left + right) / 2;
      j = (m + n + 1) / 2 - i;
      if (i < m && nums1[i] < nums2[j - 1]) {
        // i is too small
        left = i + 1;
      } else if (i > 0 && nums1[i - 1] > nums2[j]) {
        // i is too big
        right = i - 1;
      } else {
        // Found
        // i == 0 || i == m || nums1[i] >= nums2[j - 1]
        // j == 0 || j == n || nums1[i - 1] <= nums2[j]
        break;
      }
    }

    int left_max = 0;
    int right_min = 0;
    if (i == 0) {
      left_max = nums2[j - 1];
    } else if (j == 0) {
      left_max = nums1[i - 1];
    } else {
      left_max = std::max(nums1[i - 1], nums2[j - 1]);
    }

    if ((m + n) & 0x1) {
      // Avoid j overflow
      return (double)left_max;
    }

    if (i == m) {
      right_min = nums2[j];
    } else if (j == n) {
      right_min = nums1[i];
    } else {
      right_min = std::min(nums1[i], nums2[j]);
    }

    return ((left_max + right_min) / 2.0);
  }
};

class Solution2 {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    const int a = (nums1.size() + nums2.size() - 1) / 2;
    const int b = (nums1.size() + nums2.size()) / 2;
    int steps = 0;
    double median = 0.0;

    auto apply = [&](int val) {
      if (steps == a) {
        median = val;
      }
      if (steps == b) {
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

TEST(Solution, maxPoints) {
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
