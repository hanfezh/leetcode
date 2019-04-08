/*
 * =====================================================================================
 *
 *       Filename:  reverse_string.cpp
 *
 *    Description:  344. Reverse String. Write a function that reverses a string. The 
 *                  input string is given as an array of characters char[].
 *
 *        Version:  1.0
 *        Created:  04/08/19 12:10:15
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
#include <string>

class Solution
{
public:
    void reverseString(std::vector<char>& s)
    {
        int i = 0;
        int j = s.size() - 1;
        char chr = '\0';
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
    std::string s = "hello";
    if (argc > 1)
    {
        s = argv[1];
    }

    std::vector<char> r(s.begin(), s.end());
    Solution().reverseString(r);
    printf("Input: `%s`\n", s.c_str());
    printf("Reverse: `%s`\n", std::string(r.begin(), r.end()).c_str());
    return 0;
}
