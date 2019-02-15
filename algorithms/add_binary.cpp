/*
 * =====================================================================================
 *
 *       Filename:  add_binary.cpp
 *
 *    Description:  Add Binary. Given two binary strings, return their sum.
 *
 *        Version:  1.0
 *        Created:  02/15/19 08:07:17
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
    std::string addBinary(const std::string& a, const std::string& b)
    {
        std::string sum;
        auto iter1 = a.rbegin();
        auto iter2 = b.rbegin();
        int over = 0;
        while (iter1 != a.rend() || iter2 != b.rend())
        {
            if (iter1 != a.rend() && iter2 != b.rend())
            {
                char left = *iter1 - '0';
                char right = *iter2 - '0';
                char chr = (char)(left ^ right ^ over);
                chr += '0';
                sum.insert(0, 1, chr);
                over = (left + right + over > 1 ? 1 : 0);
                iter1++;
                iter2++;
            }
            else if (iter1 != a.rend())
            {
                char left = *iter1 - '0';
                sum.insert(0, 1, (char)((left ^ over) + '0'));
                over = (left + over > 1 ? 1 : 0);
                iter1++;
            }
            else
            {
                // iter2 != b.rend()
                char right = *iter2 - '0';
                sum.insert(0, 1, (char)((right & over) + '0'));
                over = (right + over > 1 ? 1 : 0);
                iter2++;
            }
        }

        if (over != 0)
        {
            sum.insert(0, 1, '1');
        }

        return sum;
    }
};

int main(int argc, char* argv[])
{
    std::string a = "1010";
    std::string b = "1011";
    if (argc >= 3)
    {
        a = argv[1];
        b = argv[2];
    }

    auto sum = Solution().addBinary(a, b);
    printf("%s + %s = %s\n", a.c_str(), b.c_str(), sum.c_str());

    return 0;
}
