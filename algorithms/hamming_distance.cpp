// 461. Hamming Distance: https://leetcode.com/problems/hamming-distance
// Author: xianfeng.zhu@gmail.com

#include <stdio.h>

class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int n = 0;
        unsigned int z = x ^ y;
        
        while (z != 0)
        {
            if (z & 0x01)
            {
                n++;
            }
            z >>= 1;
        }
        
        return n;
    }
};

int main(int argc, char* argv[])
{
    int x = 1;
    int y = 4;
    int n = Solution().hammingDistance(x, y);
    printf("Input: x = %d, y = %d\n", x, y);
    printf("Output: %d\n", n);
    return 0;
}
