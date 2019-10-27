// 509. Fibonacci Number: https://leetcode.com/problems/fibonacci-number
// Author: xianfeng.zhu@gmail.com

#include <stdio.h>
#include <unordered_map>

// Recursive
class Solution
{
public:
    int fib(int n)
    {
        std::unordered_map<int, int> cache;
        cache[0] = 0;
        cache[1] = 1;
        return fib(n, cache);
    }

private:
    int fib(int n, std::unordered_map<int, int>& cache)
    {
        auto iter = cache.find(n);
        if (iter != cache.end())
        {
            return iter->second;
        }

        int val = fib(n - 2, cache) + fib(n - 1, cache);
        cache[n] = val;
        return val;
    }
};

int main(int argc, char* argv[])
{
    int num = 5;
    if (argc > 1)
    {
        num = atoi(argv[1]);
    }
    int val = Solution().fib(num);
    printf("%d -> %d\n", num, val);
    return 0;
}
