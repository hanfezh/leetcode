// =====================================================================================
//
//       Filename:  sqrt.cpp
//
//    Description:  69. Sqrt(x)
//
//        Version:  1.0
//        Created:  11/05/2019 07:10:15 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

class Solution
{
public:
    int mySqrt(int x)
    {
        int left = 1;
        int right = x;
        while (left < right)
        {
            int mid = ((uint64_t)left + right) / 2;
            uint64_t val = (uint64_t)mid * mid;
            if (val > x)
            {
                right = mid - 1;
            }
            else if (val < x)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }

        return (((uint64_t)left * left) <= x ? left : (left - 1));
    }
};

int main(int argc, char* argv[])
{
    int x = 10;
    if (argc > 1)
    {
        x = atoi(argv[1]);
    }
    int val = Solution().mySqrt(x);
    printf("sqrt(%d) = %d\n", x, val);
    return 0;
}
