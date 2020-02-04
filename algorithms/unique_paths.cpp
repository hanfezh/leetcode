/*
 * =====================================================================================
 *
 *       Filename:  unique_paths.cpp
 *
 *    Description:  Unique Paths: A robot is located at the top-left corner of a m x n 
 *                  grid (marked 'Start' in the diagram below). The robot can only move 
 *                  either down or right at any point in time. The robot is trying to 
 *                  reach the bottom-right corner of the grid (marked 'Finish' in the 
 *                  diagram below). How many possible unique paths are there?
 *
 *        Version:  1.0
 *        Created:  09/14/18 08:25:14
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
#include <vector>

// Recursive
class Solution1
{
public:
    int uniquePaths(int m, int n)
    {
        if (m < 1 || n < 1)
        {
            // Invalid
            return 0;
        }
        else if (m < 2 || n < 2)
        {
            return 1;
        }

        std::vector<std::vector<int>> dp(m, std::vector<int>(n, -1));
        dp[0][0] = 0;
        dp[1][0] = 1;
        dp[0][1] = 1;

        return uniquePaths(m - 1, n - 1, dp);
    }

private:
    int uniquePaths(int m, int n, std::vector<std::vector<int>>& dp)
    {
        if (m < 0 || n < 0)
        {
            return 0;
        }
        else if (m == 0 || n == 0)
        {
            return 1;
        }
        if (dp[m][n] != -1)
        {
            return dp[m][n];
        }

        dp[m][n] = uniquePaths(m - 1, n, dp) + uniquePaths(m, n - 1, dp);
        return dp[m][n];
    }
};

// Intuitive
class Solution2
{
public:
    int uniquePaths(int m, int n)
    {
        if (m < 1 || n < 1)
        {
            // Invalid
            return 0;
        }
        else if (m < 2 || n < 2)
        {
            return 1;
        }
        
        std::vector<std::vector<int>> paths(m, std::vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0)
                {
                    paths[i][j] = 1;
                }
                else
                {
                    paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
                }
            }
        }
        
        return paths[m - 1][n - 1];
    }
};

using Solution = Solution2;

int main(int argc, char* argv[])
{
    int m = 3;
    int n = 7;

    if (argc == 3)
    {
        m = atoi(argv[1]);
        n = atoi(argv[2]);
    }

    int sum = Solution().uniquePaths(m, n);
    printf("[%d, %d] -> %d\n", m, n, sum);

    return 0;
}
