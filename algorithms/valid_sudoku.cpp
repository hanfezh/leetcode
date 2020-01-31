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
#include <assert.h>
#include <string>
#include <vector>
#include <unordered_set>

// Brute force
class Solution1
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

// Hash table
class Solution2
{
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board)
    {
        if (board.size() != 9)
        {
            return false;
        }

        std::unordered_set<std::string> seen;
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i].size() != 9)
            {
                return false;
            }

            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }

                std::string num = std::string(1, board[i][j]);
                if (!seen.insert(num + " in row " + std::to_string(i)).second ||
                    !seen.insert(num + " in column " + std::to_string(j)).second ||
                    !seen.insert(num + " in block " + std::to_string(i / 3) + "-" + std::to_string(j / 3)).second)
                {
                    // Already exists, insert failed
                    return false;
                }
            }
        }

        return true;
    }
};

using Solution = Solution2;

int main(int argc, char* argv[])
{
    std::vector<std::vector<char>> board1 = {
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

    std::vector<std::vector<char>> board2 = {
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

    bool valid = Solution().isValidSudoku(board1);
    assert(valid == true);
    printf("Sudoku is %s.\n", (valid ? "valid" : "invalid"));

    valid = Solution().isValidSudoku(board2);
    assert(valid == false);
    printf("Sudoku is %s.\n", (valid ? "valid" : "invalid"));

    return 0;
}
