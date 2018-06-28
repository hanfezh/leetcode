/*
 * =====================================================================================
 *
 *       Filename:  three_sum.c
 *
 *    Description:  Given an array nums of n integers, are there elements a, b, c in 
 *                  nums such that a + b + c = 0? Find all unique triplets in the array 
 *                  which gives the sum of zero.
 *
 *        Version:  1.0
 *        Created:  06/27/18 07:08:33
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

static int cmpInt(const void* a, const void* b)
{
    int x = *(const int*)a;
    int y = *(const int*)b;
    if (x < y)
    {
        return -1;
    }
    else if (x > y)
    {
        return 1;
    }
    return 0;
}

/**
 * Return an array of arrays of size *ret_size.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int nums_size, int* ret_size)
{
    if (nums_size < 3)
    {
        *ret_size = 0;
        return NULL;
    }

    // Sort input array
    qsort(nums, nums_size, sizeof(int), cmpInt);

    int alloc_idx = 0;
    int** alloc_data = NULL;
    for (int i = 0; i < nums_size; i++)
    {
        int sum = 0;
        int start = i + 1;
        int end = nums_size - 1;

        while (start < end)
        {
            sum = nums[i] + nums[start] + nums[end];
            if (sum == 0)
            {
                int found = 0;
                for (int n = 0; n < alloc_idx; n++)
                {
                    if (nums[i] == alloc_data[n][0] &&
                        nums[start] == alloc_data[n][1] &&
                        nums[end] == alloc_data[n][2])
                    {
                        found = 1;
                        break;
                    }
                }

                if (!found)
                {
                    alloc_data = realloc(alloc_data, sizeof(int*) * (alloc_idx + 1));
                    alloc_data[alloc_idx] = malloc(sizeof(int) * 3);

                    int* tmp_arr = alloc_data[alloc_idx];
                    tmp_arr[0] = nums[i];
                    tmp_arr[1] = nums[start];
                    tmp_arr[2] = nums[end];
                    alloc_idx++;
                }
                start++;
                end--;
            }
            else if (sum < 0)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }

    *ret_size = alloc_idx;
    return alloc_data;
}

int main(int argc, char* argv[])
{
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int arr_size = 0;
    int** alloc_arr = threeSum(nums, (sizeof(nums) / sizeof(int)), &arr_size);
    int* tmp_arr;
    int i;
    for (i = 0; i < arr_size; i++)
    {
        tmp_arr = alloc_arr[i];
        printf("%d, %d, %d\n", tmp_arr[0], tmp_arr[1], tmp_arr[2]);
    }

    free(alloc_arr);

    return 0;
}
