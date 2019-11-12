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
#include <stdio.h>
#include <vector>

using std::vector;

// Binary search
class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        if (nums2.size() == 0)
        {
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

        while (left <= right)
        {
            i = (left + right) / 2;
            j = (m + n + 1) / 2 - i;
            if (i < m && nums1[i] < nums2[j - 1])
            {
                // i is too small
                left = i + 1;
            }
            else if (i > 0 && nums1[i - 1] > nums2[j])
            {
                // i is too big
                right = i - 1;
            }
            else
            {
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
            // Ignore j overflow
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

int main(int argc, char* argv[])
{
    vector<int> nums1 = {};
    vector<int> nums2 = {2};
    double median = Solution().findMedianSortedArrays(nums1, nums2);
    printf("Median is %f\n", median);
    return 0;
}
