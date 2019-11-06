// =====================================================================================
//
//       Filename:  guess_number_higher_or_lower.cpp
//
//    Description:  374. Guess Number Higher or Lower.
//
//        Version:  1.0
//        Created:  11/06/2019 09:57:30 AM
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

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num)
{
    const int target = 6;
    return ((target < num) ? -1 : ((target > num) ? 1 : 0));
}

class Solution
{
public:
    int guessNumber(int n)
    {
        int64_t left = n;
        int64_t right = n;
        while (guess(left) == -1)
        {
            left /= 2;
        }
        while (guess(right) == 1)
        {
            right *= 2;
        }
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int ret = guess(mid);
            if (ret == -1)
            {
                right = mid - 1;
            }
            else if (ret == 1)
            {
                left = mid + 1;
            }
            else
            {
                // ret == 0
                return mid;
            }
        }

        return -1;
    }
};

int main(int argc, char* argv[])
{
    int num = 10;
    if (argc > 1)
    {
        num = atoi(argv[1]);
    }
    int val = Solution().guessNumber(num);
    printf("%d -> %d\n", num, val);
    return 0;
}
