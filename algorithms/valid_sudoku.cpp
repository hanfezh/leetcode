/*
 * =====================================================================================
 *
 *       Filename:  valid_sudoku.cpp
 *
 *    Description:  Valid Sudoku: Determine if a 9x9 Sudoku board is valid.
 *
 *        Version:  1.0
 *        Created:  08/07/18 12:45:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <vector>

class Solution
{
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board)
    {
        if (board.size() != 9)
        {
            return false;
        }

        for (size_t i = 0; i < (board.size() - 2); i += 3)
        {
            if (board[i].size() != 9)
            {
                return false;
            }

            for (size_t j = 0; j < (board[i].size() - 2); j += 3)
            {
                std::vector<char> box = {
                    board[i][j], board[i][j + 1], board[i][j + 2],
                    board[i + 1][j], board[i + 1][j + 1], board[i + 1][j + 2],
                    board[i + 2][j], board[i + 2][j + 1], board[i + 2][j + 2]
                };

                if (!isValidSubbox(box))
                {
                    return false;
                }
            }
        }

        for (const auto& box: board)
        {
            if (!isValidSubbox(box))
            {
                return false;
            }
        }

        for (int i = 0; i < 9; i++)
        {
            std::vector<char> box = {
                board[0][i], board[1][i], board[2][i],
                board[3][i], board[4][i], board[5][i],
                board[6][i], board[7][i], board[8][i],
            };
            if (!isValidSubbox(box))
            {
                return false;
            }
        }

        return true;
    }

private:
    bool isValidSubbox(const std::vector<char>& box)
    {
        std::vector<bool> flags;
        flags.resize(box.size() + 1);
        for (auto chr: box)
        {
            if (chr == '.')
            {
                continue;
            }

            int idx = chr - '0';
            if ((idx < flags.size()) && flags[idx])
            {
                return false;
            }
            flags[idx] = true;
        }

        return true;
    }
};

int main(int argc, char* argv[])
{
#if 0
    std::vector<std::vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
#endif

    std::vector<std::vector<char>> board = {
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','9','.','.','.','.','.','.','1'},
        {'8','.','.','.','.','.','.','.','.'},
        {'.','9','9','3','5','7','.','.','.'},
        {'.','.','.','.','.','.','.','4','.'},
        {'.','.','.','8','.','.','.','.','.'},
        {'.','1','.','.','.','.','4','.','9'},
        {'.','.','.','5','.','4','.','.','.'}
    };

    bool valid = Solution().isValidSudoku(board);
    printf("Sudoku is %s.\n", (valid ? "valid" : "invalid"));

    return 0;
}
