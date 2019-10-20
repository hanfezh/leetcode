// =====================================================================================
//
//       Filename:  pascal_triangle.cpp
//
//    Description:  118. Pascal's Triangle. 
//                  Given a non-negative integer numRows, generate the first numRows of 
//                  Pascal's triangle. In Pascal's triangle, each number is the sum of 
//                  the two numbers directly above it.
//
//        Version:  1.0
//        Created:  08/16/2019 11:46:07 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using std::vector;

// Non-recursive
class Solution1
{
public:
    vector<vector<int>> generate(int rows)
    {
        vector<vector<int>> nums;
        for (int i = 0; i < rows; i++)
        {
            nums.push_back(vector<int>(i + 1, 0));
            nums[i][0] = 1;
            if (i < 1)
            {
                continue;
            }

            nums[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                nums[i][j] = nums[i - 1][j - 1] + nums[i - 1][j];
            }
        }
        
        return nums;
    }
};

// Recursive
class Solution2
{
public:
    vector<vector<int>> generate(int rows)
    {
        vector<vector<int>> nums(rows, vector<int>());
        for (int i = 0; i < rows; i++)
        {
            nums[i].resize(i + 1);
        }
        if (rows > 0)
        {
            nums[0][0] = 1;
        }
        for (int i = 0; i < rows; i++)
        {
            nums[rows - 1][i] = generate(nums, rows - 1, i);
        }
        return nums;
    }

private:
    int generate(vector<vector<int>>& nums, int i, int j)
    {
        if (nums[i][j] != 0)
        {
            return nums[i][j];
        }
        if (i == 0 || j == 0 || i == j)
        {
            nums[i][j] = 1;
        }
        else
        {
            nums[i][j] = generate(nums, i - 1, j - 1) + generate(nums, i - 1, j);
        }

        return nums[i][j];
    }
};

using Solution = Solution2;

int main(int argc, char* argv[])
{
    int rows = 6;
    if (argc > 1)
    {
        rows = atoi(argv[1]);
    }

    auto nums = Solution().generate(rows);
    for (const auto& row: nums)
    {
        for (const auto& item: row)
        {
            printf("%d ", item);
        }
        printf("\n");
    }

    return 0;
}
