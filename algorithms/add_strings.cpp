/*
 * =====================================================================================
 *
 *       Filename:  add_strings.cpp
 *
 *    Description:  Add Strings. Given two non-negative integers num1 and num2 
 *                  represented as string, return the sum of num1 and num2.
 *
 *        Version:  1.0
 *        Created:  02/20/19 01:59:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string>

class Solution
{
public:
    std::string addStrings(const std::string& num1, const std::string& num2)
    {
        std::string sum;
        auto iter1 = num1.rbegin();
        auto iter2 = num2.rbegin();
        int exceed = 0;

        while (iter1 != num1.rend() || iter2 != num2.rend())
        {
            int val = exceed;
            if (iter1 != num1.rend())
            {
                val += *iter1 - '0';
                iter1++;
            }
            if (iter2 != num2.rend())
            {
                val += *iter2 - '0';
                iter2++;
            }

            if (val > 9)
            {
                exceed = val / 10;
                val %= 10;
            }
            else
            {
                exceed = 0;
            }

            sum.insert(0, 1, val + '0');
        }

        if (exceed > 0)
        {
            sum.insert(0, 1, exceed + '0');
        }

        return sum;
    }
};

int main(int argc, char* argv[])
{
    std::string num1 = "123";
    std::string num2 = "456";
    if (argc >= 3)
    {
        num1 = argv[1];
        num2 = argv[2];
    }

    auto num = Solution().addStrings(num1, num2);
    printf("%s + %s = %s\n", num1.c_str(), num2.c_str(), num.c_str());

    return 0;
}
