/*
 * =====================================================================================
 *
 *       Filename:  reverse_string2.cpp
 *
 *    Description:  541. Reverse String II.
 *
 *        Version:  1.0
 *        Created:  04/09/19 12:56:46
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
#include <string>

class Solution
{
public:
    std::string reverseStr(std::string& s, int k)
    {
        if (k < 2)
        {
            return s;
        }

        for (int i = 0; i < s.size(); i += (2 * k))
        {
            int j = i + k - 1;
            if (j >= s.size())
            {
                j = s.size() - 1;
            }
            reverseStr(s, i, j);
        }

        return s;
    }

private:
    void reverseStr(std::string& s, int i, int j)
    {
        char chr;
        while (i < j)
        {
            chr = s[i];
            s[i] = s[j];
            s[j] = chr;
            i++;
            j--;
        }
    }
};

int main(int argc, char* argv[])
{
    std::string s = "abcdefg";
    int k = 2;
    auto r = Solution().reverseStr(s, k);
    printf("Input: `%s`\nOutput: `%s`\n", s.c_str(), r.c_str());
    return 0;
}
