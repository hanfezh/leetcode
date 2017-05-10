/*
 * =====================================================================================
 *
 *       Filename:  rotate_array.c
 *
 *    Description:  Rotate an array of n elements to the right by k steps.
 *                  For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is 
 *                  rotated to [5,6,7,1,2,3,4].
 *
 *        Version:  1.0
 *        Created:  2015/02/24 12时37分11秒
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
#include <string.h>

void rotate(int nums[], int n, int k)
{
	int *arr = NULL;
	int *ptr;
	int m;
	int i;

	k %= n;
	if (k == 0) {
		return;
	}

	if (k <= n / 2) {
		m = k;
		arr = malloc(sizeof(int) * m);
		ptr = (int *)nums + (n - m);
		memcpy(arr, ptr, sizeof(int) * m);

		for (i = n - 1; i >= m; i--) {
			nums[i] = nums[i - m];
		}

		ptr = (int *)nums;
		memcpy(ptr, arr, sizeof(int) * m);
	} else {
		m = n - k;
		arr = malloc(sizeof(int) * m);
		ptr = (int *)nums;
		memcpy(arr, ptr, sizeof(int) * m);

		for (i = 0; i < k; i++) {
			nums[i] = nums[i + m];
		}

		ptr = (int *)nums + k;
		memcpy(ptr, arr, sizeof(int) * m);
	}

	if (arr) {
		free(arr);
	}
}

int main(int argc, char *argv[])
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int i;

	rotate(arr, 7, 4);
	for (i = 0; i < 7; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
