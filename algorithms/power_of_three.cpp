// 326. Power of Three: https://leetcode.com/problems/power-of-three
// Author: xianfeng.zhu@gmail.com

#include <stdio.h>
#include <stdlib.h>

// Iterative loop
class Solution1
{
public:
    bool isPowerOfThree(int n)
    {
        if (n < 1)
        {
            return false;
        }
        while ((n % 3) == 0)
        {
            n /= 3;
        }
        return (n == 1);
    }
};

// Integer limitation trick
class Solution2
{
public:
    bool isPowerOfThree(int n)
    {
        // 3**19 = 1162261467 is smaller than INT_MAX
        // 3**20 is bigger than INT_MAX
        return (n > 0 && (1162261467 % n) == 0);
    }
};

using Solution = Solution2;

int main(int argc, char* argv[])
{
    int n = 27;
    if (argc > 1)
    {
        n = atoi(argv[1]);
    }
    bool is_power = Solution().isPowerOfThree(n);
    printf("Input: %d\n", n);
    printf("Output: %s\n", (is_power ? "true" : "false"));
    return 0;
}
