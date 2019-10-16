// 59. Spiral Matrix II: https://leetcode.com/problems/spiral-matrix-ii
// Author: xianfeng.zhu@gmail.com

#include <stdio.h>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> generateMatrix(int n)
    {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
        std::vector<int> dr = {0, 1, 0, -1}; // right, down, left, up
        std::vector<int> dc = {1, 0, -1, 0}; // right, down, left, up
        int di = 0; // direction index
        int ri = 0; // row index
        int ci = 0; // column index
        int val = 1;

        for (int i = 0; i < n * n; i++)
        {
            matrix[ri][ci] = val++;
            int nr = ri + dr[di]; // next row
            int nc = ci + dc[di]; // next column
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && !matrix[nr][nc])
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

        return matrix;
    }
};

int main(int argc, char* argv[])
{
    int n = 3;
    if (argc > 1)
    {
        n = atoi(argv[1]);
    }
    auto matrix = Solution().generateMatrix(n);
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
