/*
 * =====================================================================================
 *
 *       Filename:  unique_paths2.cpp
 *
 *    Description:  Unique Paths II: A robot is located at the top-left corner of a m x n 
 *                  grid (marked 'Start' in the diagram below). The robot can only move 
 *                  either down or right at any point in time. The robot is trying to 
 *                  reach the bottom-right corner of the grid (marked 'Finish' in the 
 *                  diagram below). Now consider if some obstacles are added to the grids. 
 *                  How many unique paths would there be?
 *
 *        Version:  1.0
 *        Created:  10/18/18 11:32:42
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

class Solution
{
public:
    int uniquePathsWithObstacles(const std::vector<std::vector<int>>& obstacle_grid)
    {
        if (obstacle_grid.size() < 1)
        {
            // Invalid
            return 0;
        }
        int m = obstacle_grid.size();
        int n = obstacle_grid[0].size();
        if (n < 1)
        {
            // Invalid
            return 0;
        }

        if (obstacle_grid[0][0] != 0 || obstacle_grid[m - 1][n - 1] != 0)
        {
            return 0;
        }

        std::vector<std::vector<int>> dp(m, std::vector<int>(n, -1));
        dp[0][0] = 1;
        if (m > 1)
        {
            dp[1][0] = (obstacle_grid[1][0] == 0 ? 1 : 0);
        }
        if (n > 1)
        {
            dp[0][1] = (obstacle_grid[0][1] == 0 ? 1 : 0);
        }

        return uniquePaths(m - 1, n - 1, obstacle_grid, dp);
    }

private:
    int uniquePaths(int m, int n, const std::vector<std::vector<int>>& obstacle_grid, std::vector<std::vector<int>>& dp)
    {
        if (n >= obstacle_grid[m].size())
        {
            // Invalid
            return 0;
        }

        if (m < 0 || n < 0)
        {
            return 0;
        }
        if (dp[m][n] != -1)
        {
            return dp[m][n];
        }
        if (obstacle_grid[m][n] != 0)
        {
            dp[m][n] = 0;
            return 0;
        }

        dp[m][n] = uniquePaths(m - 1, n, obstacle_grid, dp) + uniquePaths(m, n - 1, obstacle_grid, dp);
        return dp[m][n];
    }
};

int main(int argc, char* argv[])
{
    std::vector<std::vector<int>> obstacle_grid = {
        // {0, 0, 0},
        // {0, 1, 0},
        // {0, 0, 0}

        {0, 0},
        {1, 1},
        {0, 0}
    };

    int sum = Solution().uniquePathsWithObstacles(obstacle_grid);
    printf("Unique paths with obstacles: %d\n", sum);

    return 0;
}
