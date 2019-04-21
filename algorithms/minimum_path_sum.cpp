/*
 * =====================================================================================
 *
 *       Filename:  minimum_path_sum.cpp
 *
 *    Description:  64. Minimum Path Sum. Given a m x n grid filled with non-negative 
 *                  numbers, find a path from top left to bottom right which minimizes 
 *                  the sum of all numbers along its path.
 *
 *        Version:  1.0
 *        Created:  04/21/19 11:45:39
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
#include <vector>

class Solution
{
public:
    int minPathSum(std::vector<std::vector<int>>& grid)
    {
        if (grid.empty() || grid[0].empty())
        {
            return 0;
        }

        std::vector<std::vector<int>> sums(grid.size() + 1, 
            std::vector<int>(grid[0].size() + 1, 0));
        for (int i = grid.size() - 1; i >= 0; i--)
        {
            const auto& row = grid[i];
            auto& curr = sums[i];
            auto& prev = sums[i + 1];
            for (int j = row.size() - 1; j >= 0; j--)
            {
                if (i == (grid.size() - 1))
                {
                    curr[j] = curr[j + 1] + row[j];
                }
                else if (j == (row.size() - 1))
                {
                    curr[j] = prev[j] + row[j];
                }
                else
                {
                    curr[j] = std::min(prev[j], curr[j + 1]) + row[j];
                }
            }
        }

        return sums[0][0];
    }
};

int main(int argc, char* argv[])
{
    std::vector<std::vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1},
    };
    int sum = Solution().minPathSum(grid);
    printf("Minimum path sum: %d\n", sum);
    return 0;
}

