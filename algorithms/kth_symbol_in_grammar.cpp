// 779. K-th Symbol in Grammar: https://leetcode.com/problems/k-th-symbol-in-grammar
// Author: xianfeng.zhu@gmail.com

#include <stdio.h>
#include <stdlib.h>

class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        if (n == 1)
        {
            return 0;
        }
        int symbol = kthGrammar(n - 1, (k + 1) / 2);
        if (symbol == 0)
        {
            return ((k & 0x1) ? 0 : 1);
        }
        else
        {
            // symbol == 1
            return ((k & 0x1) ? 1 : 0);
        }
    }
};

int main(int argc, char* argv[])
{
    int n = 4;
    int k = 5;
    if (argc > 2)
    {
        n = atoi(argv[1]);
        k = atoi(argv[2]);
    }

    int symbol = Solution().kthGrammar(n, k);
    printf("%d %d -> %d\n", n, k, symbol);
    return 0;
}
