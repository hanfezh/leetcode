/*
 * =====================================================================================
 *
 *       Filename:  valid_palindrome.cpp
 *
 *    Description:  125. Valid Palindrome. 
 *                  Given a string, determine if it is a palindrome, considering only 
 *                  alphanumeric characters and ignoring cases.
 *
 *        Version:  1.0
 *        Created:  04/08/19 11:29:07
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
#include <ctype.h>
#include <string>

class Solution
{
public:
    bool isPalindrome(const std::string &s)
    {
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            if (!isalnum(s.at(i)))
            {
                i++;
                continue;
            }
            if (!isalnum(s.at(j)))
            {
                j--;
                continue;
            }
            if (toupper(s.at(i)) != toupper(s.at(j)))
            {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};

int main(int argc, char* argv[])
{
    std::string s = "A man, a plan, a canal: Panama";
    auto is_pal = Solution().isPalindrome(s);
    printf("Input: `%s`, is palindrome? %s\n", s.c_str(), (is_pal ? "Yes" : "No"));
    return 0;
}
