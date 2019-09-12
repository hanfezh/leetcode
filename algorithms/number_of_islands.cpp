// =====================================================================================
//
//       Filename:  number_of_islands.cpp
//
//    Description:  200. Number of Islands.
//
//        Version:  1.0
//        Created:  09/12/2019 01:20:27 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <vector>

class UnionFind
{
public:
    UnionFind(int count): count_(count)
    {
        buf_ = new int[count];
        for (int i = 0; i < count; i++)
        {
            buf_[i] = i;
        }
    }

    virtual ~UnionFind()
    {
        delete[] buf_;
        buf_ = nullptr;
    }

    int find(int idx) const
    {
        while (buf_[idx] != idx)
        {
            idx = buf_[idx];
        }

        return idx;
    }

    void connect(int a, int b)
    {
        int i = find(a);
        int j = find(b);
        if (i == j)
        {
            return;
        }

        buf_[i] = j;
        count_ -= 1;
    }

    bool isConnected(int a, int b) const
    {
        return find(a) == find(b);
    }

    int getCount() const
    {
        return count_;
    }

private:
    int count_ = 0;
    int* buf_ = nullptr;
};

class Solution
{
public:
    int numIslands(std::vector<std::vector<char>>& grid)
    {
        if (grid.size() == 0 || grid[0].size() == 0)
        {
            return 0;
        }

        int m = grid.size();
        int n = grid[0].size();
        UnionFind uf(m * n);
        int zeros = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != '1')
                {
                    zeros++;
                    continue;
                }

                if (j > 0 && grid[i][j - 1] == '1')
                {
                    // Connect current and left node
                    uf.connect(i * n + j, i * n + j - 1);
                }
                if (i > 0 && grid[i - 1][j] == '1')
                {
                    // Connect current and upper node
                    uf.connect(i * n + j, (i - 1) * n + j);
                }
            }
        }

        return (uf.getCount() - zeros);
    }
};

int main(int argc, char* argv[])
{
    std::vector<std::vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'},
    };
    int num = Solution().numIslands(grid);
    printf("num = %d\n", num);
    return 0;
}
