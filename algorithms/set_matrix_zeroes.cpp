// =====================================================================================
//
//       Filename:  set_matrix_zeroes.cpp
//
//    Description:  73. Set Matrix Zeroes. Given a m x n matrix, if an element is 0, set
//                  its entire row and column to 0. Do it in-place.
//
//        Version:  1.0
//        Created:  10/18/2019 04:57:45 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <algorithm>
#include <vector>

using std::vector;

class Solution
{
public:
    enum ZeroState
    {
        kZeroEmpty = 0,
        kZeroHorizontal = 1,
        kZeroVertical = 2,
    };

    void setZeroes(vector<vector<int>>& matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        int n = std::max(rows, cols);
        vector<int> states(n, kZeroEmpty);

        // Keep zero cells in matrix
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    states[i] |= kZeroHorizontal;
                    states[j] |= kZeroVertical;
                }
            }
        }

        // Set zero by zero states
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (states[i] & kZeroHorizontal || states[j] & kZeroVertical)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main(int argc, char* argv[])
{
    vector<vector<int>> matrix = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5},
    };

    Solution().setZeroes(matrix);
    for (const auto& row: matrix)
    {
        for (const auto& val: row)
        {
            printf("%d ", val);
        }
        printf("\n");
    }

    return 0;
}
