/*
 * =====================================================================================
 *
 *       Filename:  rotated_digits.cpp
 *
 *    Description:  Rotated Digits. 
 *                  X is a good number if after rotating each digit individually by 180 
 *                  degrees, we get a valid number that is different from X. Each digit 
 *                  must be rotated - we cannot choose to leave it alone. Now given a 
 *                  positive number N, how many numbers X from 1 to N are good?
 *
 *        Version:  1.0
 *        Created:  02/19/19 12:29:41
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

class Solution
{
public:
    int rotatedDigits(int num)
    {
        std::vector<int> sum(num + 1, 0);
        
        for (int i = 1; i <= num; i++)
        {
            sum[i] = sum[i - 1] + isValidNumber(i);
        }

        return sum[num];
    }

private:
    bool isValidNumber(int num)
    {
        bool changed = false;

        while (num > 0)
        {
            int unit = num % 10;
            if (unit == 2 || unit == 5 || unit == 6 || unit == 9)
            {
                // Value changed
                changed = true;
            }
            else if (unit == 3 || unit == 4 || unit == 7)
            {
                // Invalid number
                return false;
            }
            else
            {
                ; // 0, 1, 8, value not changed 
            }

            num = num / 10;
        }

        return changed;
    }
};

int main(int argc, char* argv[])
{
    int num = 10;
    if (argc > 1)
    {
        num = atoi(argv[1]);
    }

    auto count = Solution().rotatedDigits(num);
    printf("%d -> %d\n", num, count);

    return 0;
}
