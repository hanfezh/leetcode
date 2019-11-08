// =====================================================================================
//
//       Filename:  valid_perfect_square.cpp
//
//    Description:  367. Valid Perfect Square.
//                  Given a positive integer num, write a function which returns True if
//                  num is a perfect square else False.
//
//        Version:  1.0
//        Created:  11/08/2019 04:10:37 PM
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
    bool isPerfectSquare(int num)
    {
        int left = 1;
        int right = num;
        while (left <= right)
        {
            uint64_t mid = ((uint64_t)left + right) / 2;
            uint64_t square = mid * mid;
            if (square > num)
            {
                right = mid - 1;
            }
            else if (square < num)
            {
                left = mid + 1;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char* argv[])
{
    int num = 2147483647; // INT_MAX
    if (argc > 1)
    {
        num = atoi(argv[1]);
    }

    bool valid = Solution().isPerfectSquare(num);
    printf("Is perfect square, %d? %s\n", num, (valid ? "Yes" : "No"));
    return 0;
}
