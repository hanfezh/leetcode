// =====================================================================================
//
//       Filename:  reverse_bits.cpp
//
//    Description:  190. Reverse Bits.
//
//        Version:  1.0
//        Created:  08/21/2019 07:58:47 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <stdint.h>

// Use extra variable
class Solution1
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        int m = 0;
        for (int i = 0; i < 32; i++)
        {
            m = (m << 1) | (n & 0x1);
            n >>= 1;
        }
        return m;
    }
};

// Binary search
class Solution2
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};

using Solution = Solution2;

int main(int argc, char* argv[])
{
    uint32_t n = 43261596;
    uint32_t m = Solution().reverseBits(n);
    printf("%d -> %d\n", n, m);
    return 0;
}
