/*
 * =====================================================================================
 *
 *       Filename:  missing_number.cpp
 *
 *    Description:  Missing number. Given an array containing n distinct numbers taken 
 *                  from 0, 1, 2, ..., n, find the one that is missing from the array.
 *
 *        Version:  1.0
 *        Created:  03/05/19 01:43:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

class Solution
{
public:
    int missingNumber(std::vector<int>& nums)
    {
#ifdef __STD_SORT__
        std::sort(nums.begin(), nums.end());
#else
        quickSort(nums, 0, nums.size() - 1);
#endif

        int supposed = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] != supposed)
            {
                // Find missing
                break;
            }
            supposed++;
        }

        return supposed;
    }

private:
    void quickSort(std::vector<int>& nums, int left, int right)
    {
        if (left < right)
        {
            int middle = partition(nums, left, right);
            quickSort(nums, left, middle - 1);
            quickSort(nums, middle + 1, right);
        }
    }

    int partition(std::vector<int>& nums, int left, int right)
    {
        int midval = nums[right];
        int last = left;
        for (int i = left; i < right; i++)
        {
            if (nums[i] >= midval)
            {
                continue;
            }
            if (last != i)
            {
                swap(&nums[last], &nums[i]);
            }
            last++;
        }
        if (last != right)
        {
            swap(&nums[last], &nums[right]);
        }
        return last;
    }

    void swap(int* a, int* b)
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {3, 0, 1};
    if (argc > 1)
    {
        nums.clear();
        for (int i = 1; i < argc; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
    }
    auto missing = Solution().missingNumber(nums);
    printf("Missing number: %d\n", missing);
    return 0;
}
