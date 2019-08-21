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

class Solution
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

int main(int argc, char* argv[])
{
    uint32_t n = 43261596;
    uint32_t m = Solution().reverseBits(n);
    printf("%d -> %d\n", n, m);
    return 0;
}
