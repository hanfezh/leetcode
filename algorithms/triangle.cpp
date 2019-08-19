// =====================================================================================
//
//       Filename:  triangle.cpp
//
//    Description:  120. Triangle. 
//                  Given a triangle, find the minimum path sum from top to bottom. Each 
//                  step you may move to adjacent numbers on the row below.
//
//        Version:  1.0
//        Created:  08/19/2019 05:48:16 PM
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
    int minimumTotal(vector<vector<int>>& triangle)
    {
        if (triangle.size() == 0 || triangle[0].size() == 0)
        {
            return 0;
        }

        vector<vector<int>> sums;
        sums.push_back(triangle[0]);

        for (int i = 1; i < triangle.size(); i++)
        {
            const auto& row = triangle[i];
            sums.push_back(vector<int>(row.size()));
            sums[i][0] = sums[i - 1][0] + row.front();
            sums[i][row.size() - 1] = sums[i - 1][row.size() - 2] + row.back();

            for (int j = 1; j < row.size() - 1; j++)
            {
                sums[i][j] = std::min(sums[i - 1][j - 1], sums[i - 1][j]) + row[j];
            }
        }

        const auto& last_row = sums.back();
        int min_sum = last_row[0];
        for (int i = 1; i < last_row.size(); i++)
        {
            if (last_row[i] < min_sum)
            {
                min_sum = last_row[i];
            }
        }

        return min_sum;
    }
};

int main(int argc, char* argv[])
{
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3},
    };

    int min_sum = Solution().minimumTotal(triangle);
    printf("Minimum path sum: %d\n", min_sum);

    return 0;
}
