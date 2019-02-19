/*
 * =====================================================================================
 *
 *       Filename:  length_of_last_word.cpp
 *
 *    Description:  Length of Last Word. Given a string s consists of upper/lower-case 
 *                  alphabets and empty space characters ' ', return the length of last 
 *                  word in the string.
 *
 *        Version:  1.0
 *        Created:  02/19/19 12:00:08
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
    int lengthOfLastWord(const std::string& str)
    {
        int prev = -1;
        int len = 0;
        int i = 0;

        for (i = 0; i < str.size(); i++)
        {
            if (prev == -1 && str[i] != ' ')
            {
                prev = i;
            }
            else if (prev != -1 && str[i] == ' ')
            {
                len = i - prev;
                prev = -1;
            }
        }

        if (prev != -1 && i == str.size())
        {
            len = i - prev;
        }

        return len;
    }
};

int main(int argc, char* argv[])
{
    std::string str = "Hello World";
    if (argc > 1)
    {
        str = argv[1];
    }

    auto len = Solution().lengthOfLastWord(str);
    printf("Input: `%s`\nLength of last word: %d\n", str.c_str(), len);

    return 0;
}

