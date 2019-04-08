/*
 * =====================================================================================
 *
 *       Filename:  valid_palindrome2.cpp
 *
 *    Description:  680. Valid Palindrome II. Given a non-empty string s, you may delete 
 *                  at most one character. Judge whether you can make it a palindrome.
 *
 *        Version:  1.0
 *        Created:  04/08/19 11:48:42
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
    bool validPalindrome(const std::string& s)
    {
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            if (s.at(i) != s.at(j))
            {
                return isPalindrome(s, i + 1, j) || 
                       isPalindrome(s, i, j - 1);
            }
            i++;
            j--;
        }

        return true;
    }

private:
    bool isPalindrome(const std::string &s, int i, int j)
    {
        while (i < j)
        {
            if (s.at(i) != s.at(j))
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
    std::string s = "abca";
    if (argc > 1)
    {
        s = argv[1];
    }
    auto valid = Solution().validPalindrome(s);
    printf("Input: `%s`.\nIs valid palindrome? %s\n", s.c_str(), (valid ? "Yes" : "No"));
    return 0;
}
