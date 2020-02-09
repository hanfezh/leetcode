/*
 * =====================================================================================
 *
 *       Filename:  merge_sorted_array.cpp
 *
 *    Description:  Merge Sorted Array. Given two sorted integer arrays nums1 and nums2, 
 *                  merge nums2 into nums1 as one sorted array.
 *
 *        Version:  1.0
 *        Created:  02/18/19 04:42:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <vector>

// Intuitive
class Solution1
{
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
    {
        int last = 0;
        for (int i = 0; i < n; i++)
        {
            while ((last < m) && (nums1[last] < nums2[i]))
            {
                last++;
            }

            for (int j = m; j > last; j--)
            {
                nums1[j] = nums1[j - 1];
            }
            nums1[last] = nums2[i];
            m++;
        }
    }
};

// Two pointers
class Solution2
{
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
    {
        int k = m + n;
        int i = m - 1;
        int j = n - 1;

        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[--k] = nums1[i--];
            }
            else
            {
                nums1[--k] = nums2[j--];
            }
        }
        while (j >= 0)
        {
            nums1[--k] = nums2[j--];
        }
    }
};

using Solution = Solution2;

int main(int argc, char* argv[])
{
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};
    Solution().merge(nums1, 3, nums2, 3);
    for (auto val: nums1)
    {
        printf("%d ", val);
    }
    printf("\n");

    return 0;
}
