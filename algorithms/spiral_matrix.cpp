// 54. Spiral Matrix: https://leetcode.com/problems/spiral-matrix
// Author: xianfeng.zhu@gmail.com
#include <stdio.h>
#include <vector>

class Solution
{
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return std::vector<int>();
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
        std::vector<int> values;
        std::vector<int> dr = {0, 1, 0, -1}; // right, down, left, up
        std::vector<int> dc = {1, 0, -1, 0}; // right, down, left, up
        int di = 0; // direction index
        int ri = 0; // row index
        int ci = 0; // column index

        for (int i = 0; i < rows * cols; i++)
        {
            values.push_back(matrix[ri][ci]);
            visited[ri][ci] = true;
            int nr = ri + dr[di]; // next row
            int nc = ci + dc[di]; // next column
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc])
            {
                ri = nr;
                ci = nc;
            }
            else
            {
                di = (di + 1) % 4;
                ri += dr[di];
                ci += dc[di];
            }
        }

        return values;
    }
};

int main(int argc, char* argv[])
{
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    auto values = Solution().spiralOrder(matrix);
    for (auto val: values)
    {
        printf("%d ", val);
    }
    printf("\n");
    return 0;
}
