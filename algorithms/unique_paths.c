/*
 * =====================================================================================
 *
 *       Filename:  unique_paths.c
 *
 *    Description:  Unique Paths: A robot is located at the top-left corner of a m x n 
 *                  grid (marked 'Start' in the diagram below). The robot can only move 
 *                  either down or right at any point in time. The robot is trying to 
 *                  reach the bottom-right corner of the grid (marked 'Finish' in the 
 *                  diagram below). How many possible unique paths are there?
 *
 *        Version:  1.0
 *        Created:  09/27/18 06:42:58
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
#include <stdint.h>

int uniquePaths(int m, int n)
{
    if (m < 1 || n < 1)
    {
        // Invalid
        return 0;
    }
    else if (m == 1 || n == 1)
    {
        return 1;
    }

    // Calc permutations: [3, 7] -> [2, 6] -> C8,2

    m -= 1;
    n -= 1;

    if (n < m)
    {
        int x = n;
        n = m;
        m = x;
    }

    uint64_t sum = 1;
    int i = 1;
    int j = n + 1;
    for ( ; i <= m; i++, j++)
    {
        sum *= j;
        sum /= i;
    }

    return sum;
}

int main(int argc, char* argv[])
{
    int m = 3;
    int n = 7;

    if (argc == 3)
    {
        m = atoi(argv[1]);
        n = atoi(argv[2]);
    }

    int sum = uniquePaths(m, n);
    printf("[%d, %d] -> %d\n", m, n, sum);

    return 0;
}
