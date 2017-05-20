/*
 * =====================================================================================
 *
 *       Filename:  longest_palindrome.c
 *
 *    Description:  Longest Palindromic Substring.
 *                  Given a string s, find the longest palindromic substring in s. 
 *                  You may assume that the maximum length of s is 1000.
 *
 *        Version:  1.0
 *        Created:  05/19/2017 07:59:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng <xianfeng.zhu@gmail.com>
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string.h>


char *longestPalindrome(char *s)
{
    static char buf[1024] = {'\0'};

    char *start = NULL;
    int maxLen = 0;
    int size = strlen(s);
    int i = 0;
    int j = 0;

    if (size == 0)
    {
        return (char *)NULL;
    }

    start = s;
    maxLen = 1;

    for (i = 1; i < size; i++)
    {
        /* Case 1: aa */

        for (j = 0; j < i; j++)
        {
            if (((i + j) < size) && (s[i - j - 1] == s[i + j]))
            {
                continue;
            }

            break;
        }

        if ((2 * j) > maxLen)
        {
            maxLen = 2 * j;
            start = s + (i -j );
        }

        /* Case 2: aba */

        for (j = 0; j < i; j++)
        {
            if (((i + j + 1) < size) && (s[i - j - 1] == s[i + j + 1]))
            {
                continue;
            }

            break;
        }

        if ((2 * j + 1) > maxLen)
        {
            maxLen = 2 * j + 1;
            start = s + (i - j);
        }
    }

    memcpy(buf, start, maxLen);
    buf[maxLen] = '\0';

    return (char *)buf;
}

int main(int argc, char *argv[])
{
    // char *str = "babad";
    char *str = "cbbd";

    printf("Longest palindromic substring\n");
    printf("Input: %s\n", str);
    printf("Output: %s\n", longestPalindrome(str));

    return 0;
}
