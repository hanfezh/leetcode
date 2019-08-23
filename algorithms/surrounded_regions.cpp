// =====================================================================================
//
//       Filename:  surrounded_regions.cpp
//
//    Description:  130. Surrounded Regions.
//
//        Version:  1.0
//        Created:  08/22/2019 07:10:41 PM
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

class UnionFind
{
public:
    UnionFind(int n)
    {
        count_ = n;
        buf_ = new int[n];
        for (int i = 0; i < n; i++)
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
        count_--;
    }

    bool connected(int a, int b) const
    {
        return find(a) == find(b);
    }

    int getCount() const
    {
        return count_;
    }

private:
    int* buf_ = nullptr;
    int count_ = 0;
};

class Solution
{
public:
    void solve(vector<vector<char>>& board)
    {
        if (board.size() == 0 || board[0].size() == 0)
        {
            return;
        }
        
        int m = board.size();
        int n = board[0].size();
        int last = m * n;
        UnionFind uf(last + 1);

        // Connect adjacet node
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] != 'O')
                {
                    continue;
                }
                if (i == 0 || i == (m - 1) || j == 0 || j == (n - 1))
                {
                    // Connect boundary to last node
                    uf.connect(i * n + j, last);
                }
                if (i > 0 && board[i - 1][j] == 'O')
                {
                    // Connect current and upper node
                    uf.connect(i * n + j, (i - 1) * n + j);
                }
                if (j > 0 && board[i][j - 1] == 'O')
                {
                    // Connect current and left node
                    uf.connect(i * n + j, i * n + j - 1);
                }
            }
        }

        // Capture all regions surrounded by 'X'
        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (board[i][j] != 'O')
                {
                    continue;
                }
                if (!uf.connected(i * n + j, last))
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main(int argc, char* argv[])
{
    vector<vector<char>> board = {
        {'X', 'O', 'X', 'X'}, 
        {'O', 'X', 'O', 'X'}, 
        {'X', 'O', 'X', 'O'}, 
        {'O', 'X', 'O', 'X'}, 
        {'X', 'O', 'X', 'O'}, 
        {'O', 'X', 'O', 'X'},
    };

    Solution().solve(board);
    for (const auto& row: board)
    {
        for (const auto& chr: row)
        {
            printf("%c ", chr);
        }
        printf("\n");
    }

    return 0;
}
