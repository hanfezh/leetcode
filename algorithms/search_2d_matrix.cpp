// =====================================================================================
//
//       Filename:  search_2d_matrix.cpp
//
//    Description:  74. Search a 2D Matrix. Write an efficient algorithm that searches 
//                  for a value in an m x n matrix.
//
//        Version:  1.0
//        Created:  10/17/2019 07:56:02 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <vector>

using std::vector;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int left = 0;
        int right = matrix.size() - 1;
        while (left < right)
        {
            int middle = (left + right + 1) / 2;
            if (target < matrix[middle][0])
            {
                right = middle - 1;
            }
            else
            {
                left = middle;
            }
        }

        if (left != right)
        {
            return false;
        }

        // left == right
        const auto& values = matrix[left];
        left = 0;
        right = values.size() - 1;
        while (left < right)
        {
            int middle = (left + right + 1) / 2;
            if (target < values[middle])
            {
                right = middle - 1;
            }
            else if (target > values[middle])
            {
                left = middle + 1;
            }
            else
            {
                return true;
            }
        }

        return (left < values.size() && values[left] == target);
    }
};

int main(int argc, char* argv[])
{
    vector<vector<int>> matrix = {
        {1,   3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50},
    };
    int value = 3;
    bool found = Solution().searchMatrix(matrix, value);
    printf("Found %d? %s\n", value, (found ? "Yes" : "No"));
    return 0;
}
