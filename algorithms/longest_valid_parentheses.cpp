/*
 * =====================================================================================
 *
 *       Filename:  longest_valid_parentheses.cpp
 *
 *    Description:  32. Longest Valid Parentheses. 
 *                  Given a string containing just the characters '(' and ')', find the 
 *                  length of the longest valid (well-formed) parentheses substring.
 *
 *        Version:  1.0
 *        Created:  04/17/19 12:47:26
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
#include <algorithm>
#include <stack>
#include <string>

class Solution
{
public:
    int longestValidParentheses(std::string& s)
    {
        std::stack<int> idxes;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                idxes.push(i);
            }
            else
            {
                if (!idxes.empty() && s[idxes.top()] == '(')
                {
                    idxes.pop();
                }
                else
                {
                    idxes.push(i);
                }
            }
        }

        int longest = 0;
        int last = s.size();
        while (!idxes.empty())
        {
            longest = std::max(longest, last - idxes.top() - 1);
            last = idxes.top();
            idxes.pop();
        }

        longest = std::max(longest, last);
        return longest;
    }
};

int main(int argc, char* argv[])
{
    std::string s = ")()())";
    auto count = Solution().longestValidParentheses(s);
    printf("Input: %s\nOutput: %d\n", s.c_str(), count);
    return 0;
}
