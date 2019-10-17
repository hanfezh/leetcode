// =====================================================================================
//
//       Filename:  word_search.cpp
//
//    Description:  79. Word Search. 
//                  Given a 2D board and a word, find if the word exists in the grid.
//
//        Version:  1.0
//        Created:  10/17/2019 05:11:58 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    bool exist(vector<vector<char>>& board, string& word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (findPath(board, i, j, word, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool findPath(vector<vector<char>>& board, int i, int j, string& word, int start)
    {
        if (!isMatched(board, i, j, word, start))
        {
            return false;
        }
        if (start == word.size() - 1)
        {
            return true;
        }

        // Keep current character
        char cur_chr = board[i][j];
        board[i][j] = '\0';
        bool matched = findPath(board, i, j + 1, word, start + 1) ||
                       findPath(board, i + 1, j, word, start + 1) ||
                       findPath(board, i, j - 1, word, start + 1) ||
                       findPath(board, i - 1, j, word, start + 1);

        // Recover current character
        board[i][j] = cur_chr;
        return matched;
    }

    bool isMatched(vector<vector<char>>& board, int i, int j, string& word, int start)
    {
        return (i >= 0 && i < board.size() && j >= 0 && j < board[i].size() &&
                start < word.size() && board[i][j] == word[start]);
    }
};

int main(int argc, char* argv[])
{
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };
    string word = "ABCCED";
    bool matched = Solution().exist(board, word);
    printf("Exist? %s\n", (matched ? "Yes" : "No"));
    return 0;
}
