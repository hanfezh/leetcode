// 48. Rotate Image: https://leetcode.com/problems/rotate-image
// Author: xianfeng.zhu@gmail.com

#include <stdio.h>
#include <algorithm>
#include <vector>

using std::vector;

class Solution
{
public:
    // Clockwise rotate:
    // 1. reverse up to down
    // 2. swap the symmetry
    //    1 2 3    7 8 9    7 4 1
    //    4 5 6 => 4 5 6 => 8 5 2
    //    7 8 9    1 2 3    9 6 3
    void rotate(vector<vector<int>>& matrix)
    {
        std::reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = (i + 1); j < matrix[i].size(); j++)
            {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

int main(int argc, char* argv[])
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    Solution().rotate(matrix);
    printf("After rotate:\n");
    for (const auto& row: matrix)
    {
        for (auto val: row)
        {
            printf("%d ", val);
        }
        printf("\n");
    }
    return 0;
}
