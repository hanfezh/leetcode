// 7. Reverse Integer: https://leetcode.com/problems/reverse-integer
// Author: xianfeng.zhu@gmail.com

#include <stdio.h>
#include <limits.h>

class Solution
{
public:
    int reverse(int x)
    {
        int n = 0;
        while (x != 0)
        {
            int digit = x % 10;
            if ((n > INT_MAX / 10) || (n == INT_MAX / 10 && digit > INT_MAX % 10) ||
                (n < INT_MIN / 10) || (n == INT_MIN / 10 && digit < INT_MIN % 10))
            {
                return 0;
            }
            n = n * 10 + digit;
            x /= 10;
        }

        return n;
    }
};

int main(int argc, char* argv[])
{
    int x = -123;
    int n = Solution().reverse(x);
    printf("%d -> %d\n", x, n);
    return 0;
}
