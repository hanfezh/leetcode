/*
 * =====================================================================================
 *
 *       Filename:  climbing_stairs.cpp
 *
 *    Description:  70. Climbing Stairs. You are climbing a stair case. It takes n steps
 *                  to reach to the top. Each time you can either climb 1 or 2 steps. In 
 *                  how many distinct ways can you climb to the top?
 *
 *        Version:  1.0
 *        Created:  02/18/19 02:18:57
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
#include <unordered_map>

// Iteractive
class Solution1
{
public:
    int climbStairs(int n)
    {
        if (n < 1)
        {
            return 0;
        }

        std::vector<int> ways(n > 2 ? n : 2);
        ways[0] = 1;
        ways[1] = 2;

        for (int i = 2; i < n; i++)
        {
            ways[i] = ways[i - 1] + ways[i - 2];
        }

        return ways[n - 1];
    }
};

// Recursive
class Solution2
{
public:
    int climbStairs(int n)
    {
        std::unordered_map<int, int> cache;
        cache[0] = 0;
        cache[1] = 1;
        cache[2] = 2;
        return climbStairs(n, cache);
    }

private:
    int climbStairs(int n, std::unordered_map<int, int>& cache)
    {
        auto iter = cache.find(n);
        if (iter != cache.end())
        {
            return iter->second;
        }

        int val = climbStairs(n - 1, cache) + climbStairs(n - 2, cache);
        cache[n] = val;
        return val;
    }
};

using Solution = Solution2;

int main(int argc, char* argv[])
{
    int n = 5;
    if (argc > 1)
    {
        n = atoi(argv[1]);
    }

    int ways = Solution().climbStairs(n);
    printf("%d steps -> %d ways\n", n, ways);

    return 0;
}
