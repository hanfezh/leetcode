// 292. Nim Game: https://leetcode.com/problems/nim-game
// Author: xianfeng.zhu@gmail.com

#include <stdio.h>

class Solution
{
public:
    bool canWinNim(int n)
    {
        return ((n %= 4) > 0);
    }
};

int main(int argc, char* argv[])
{
    int n = 4;
    bool is_win = Solution().canWinNim(n);
    printf("Input: %d\n", n);
    printf("Output: %s\n", (is_win ? "true" : "false"));
    return 0;
}
