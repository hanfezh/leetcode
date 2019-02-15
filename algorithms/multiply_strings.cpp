/*
 * =====================================================================================
 *
 *       Filename:  multiply_strings.cpp
 *
 *    Description:  Multiply Strings. 
 *                  Given two non-negative integers num1 and num2 represented as strings, 
 *                  return the product of num1 and num2, also represented as a string.
 *
 *        Version:  1.0
 *        Created:  02/15/19 03:40:15
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
#include <vector>

class Solution
{
public:
    std::string multiply(const std::string& num1, const std::string& num2)
    {
        std::vector<int> values;
        values.reserve(num1.size() + num2.size());

        int idx1 = 0;
        auto iter1 = num1.rbegin();
        while (iter1 != num1.rend())
        {
            int idx2 = 0;
            auto iter2 = num2.rbegin();
            while (iter2 != num2.rend())
            {
                int i = idx1 + idx2;
                if (values.size() < (i + 1))
                {
                    values.resize(i + 1);
                }
                values[i] += (*iter1 - '0') * (*iter2 - '0');

                while (values[i] >= 10)
                {
                    if (values.size() < (i + 2))
                    {
                        values.resize(i + 2);
                    }
                    int prefix = values[i] / 10;
                    values[i] = values[i] % 10;
                    values[i + 1] += prefix;
                    i++;
                }

                iter2++;
                idx2++;
            }

            iter1++;
            idx1++;
        }

        std::string str;
        bool is_zero = true;
        auto iter = values.rbegin();
        while (iter != values.rend())
        {
            if (is_zero && (*iter == 0))
            {
                iter++;
                continue;
            }

            is_zero = false;
            str.push_back((char)(*iter + '0'));
            iter++;
        }
        if (str.empty())
        {
            str = "0";
        }

        return str;
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

    auto num = Solution().multiply(num1, num2);
    printf("%s * %s = %s\n", num1.c_str(), num2.c_str(), num.c_str());

    return 0;
}
