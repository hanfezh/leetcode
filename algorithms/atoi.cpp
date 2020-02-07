// 8. String to Integer (atoi)b)
// Author: xianfeng.zhu@gmail.com

#include <ctype.h>
#include <stdio.h>
#include <limits.h>
#include <string>

class Solution
{
public:
    int myAtoi(const std::string& str)
    {
        int num = 0;
        int idx = 0;

        // Ignore whitespace character
        while (idx < str.size() && str[idx] == ' ')
        {
            idx++;
        }
        if (idx == str.size())
        {
            return 0;
        }

        // Determine minus sign
        bool minus = false;
        if (str[idx] == '-' || str[idx] == '+')
        {
            minus = (str[idx] == '-' ? true : false);
            idx++;
        }

        while (idx < str.size() && isdigit(str[idx]) != 0)
        {
            int digit = str[idx] - '0';
            digit *= (minus ? -1 : 1);
            if ((num > INT_MAX / 10) || (num == INT_MAX / 10 && digit >= INT_MAX % 10))
            {
                // Overflow, bigger than INT_MAX
                return INT_MAX;
            }
            if ((num < INT_MIN / 10) || (num == INT_MIN / 10 && digit <= INT_MIN % 10))
            {
                // Overflow, smaller than INT_MIN
                return INT_MIN;
            }

            num = num * 10 + digit;
            idx++;
        }

        return num;
    }
};

int main(int argc, char* argv[])
{
    std::string str = "-91283472332";
    if (argc > 1)
    {
        str = argv[1];
    }
    int num = Solution().myAtoi(str);
    printf("Input: %s\n", str.c_str());
    printf("Output: %d\n", num);
    return 0;
}
