/*
 * =====================================================================================
 *
 *       Filename:  find_minimum.c
 *
 *    Description:  Find Minimum in Rotated Sorted Array.
 *                  Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *                  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *                  Find the minimum element. You may assume no duplicate exists in the array.
 *
 *        Version:  1.0
 *        Created:  2015/02/25 20时55分40秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng <xianfeng.zhu@gmail.com>
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

static int
_findMin(int arr[], int i, int j)
{
	int m;

	if (i == j) {
		return i;
	} else if (i == (j - 1)) {
		if (arr[i] < arr[j]) {
			return i;
		} else {
			return j;
		}
	}

	m = (i + j) / 2;
	if (arr[i] > arr[m]) {
		return _findMin(arr, i, m);
	} else if (arr[m] > arr[j]) {
		return _findMin(arr, m, j);
	} else {
		/* Normal sorted list */
		return i;
	}
}

int 
findMin(int num[], int n) 
{
	int idx;

   	idx = _findMin(num, 0, n - 1);
	return num[idx];
}

int main(int argc, char *argv[])
{
	int arr1[] = {4, 5, 6, 7, 0, 1, 2};
	int arr2[] = {1, 2, 3, 4, 5, 6, 7};
	int min;

	min = findMin(arr1, 7);
	printf("Min: %d\n", min);

	min = findMin(arr2, 7);
	printf("Min: %d\n", min);

	return 0;
}
