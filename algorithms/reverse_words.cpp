/*
 * =====================================================================================
 *
 *       Filename:  reverse_words.cpp
 *
 *    Description:  151. Reverse Words in a String.
 *
 *        Version:  1.0
 *        Created:  04/10/19 05:04:08
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
    std::string reverseWords(const std::string& s)
    {
        std::string r(s.size() + 1, '\0');
        size_t start = r.size();
        size_t count = 0;
        size_t idx = 0;
        while (idx < s.size())
        {
            size_t pos = s.find(' ', idx);
            if (pos == std::string::npos)
            {
                count = s.size() - idx;
                start -= count;
                r.replace(start, count, s, idx, count);
                r[--start] = ' ';
                break;
            }
            else if (pos == idx)
            {
                idx = pos + 1;
            }
            else
            {
                count = pos - idx;
                start -= count;
                r.replace(start, count, s, idx, count);
                r[--start] = ' ';
                idx = pos + 1;
            }
        }

        if (r[start] == ' ')
        {
            start++;
        }

        return r.substr(start);
    }
};

int main(int argc, char* argv[])
{
    std::string s = "the sky is blue";
    auto r = Solution().reverseWords(s);
    printf("Input: `%s`\nOutput:`%s`\n", s.c_str(), r.c_str());
    return 0;
}
