/*
 * =====================================================================================
 *
 *       Filename:  unique_binary_search_trees.cpp
 *
 *    Description:  96. Unique Binary Search Trees. Given n, how many structurally 
 *                  unique BST's (binary search trees) that store values 1 ... n?
 *
 *        Version:  1.0
 *        Created:  04/23/19 12:15:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <vector>

class Solution
{
public:
    /**
     * 1. g(n) = f(1) + f(2) + ... + f(i) + ... + f(n)
     * 2. f(i) = g(i - 1) * g(n - i)
     * -> g(n) = g(0) * g(n - 1) + g(1) * g(n - 2) + ... + g(n - 1) * g(0) 
     * -> g(i) = g(0) * g(i - 1) + g(1) * g(i - 2) + ... + g(i - 1) * g(0) 
     */
    int numTrees(int n)
    {
        if (n < 2)
        {
            return 1;
        }

        std::vector<int> g(n + 1, 0);
        g[0] = 1;
        g[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                g[i] += g[j - 1] * g[i - j];
            }
        }

        return g[n];
    }
};

int main(int argc, char* argv[])
{
    int num = 3;
    if (argc > 1)
    {
        num = atoi(argv[1]);
    }
    auto count = Solution().numTrees(num);
    printf("Input n = %d, unique trees = %d\n", num, count);
    return 0;
}
