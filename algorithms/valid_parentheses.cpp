// 20. Valid Parentheses: https://leetcode.com/problems/valid-parentheses
// Author: xianfeng.zhu@gmail.com

#include <stdio.h>
#include <stack>
#include <string>

class Solution
{
public:
    bool isValid(const std::string& s)
    {
        std::stack<char> chrs;
        for (const auto c: s)
        {
            if (c == '(') {
                chrs.push(')');
            } else if (c == '[') {
                chrs.push(']');
            } else if (c == '{') {
                chrs.push('}');
            } else if (!chrs.empty() && chrs.top() == c) {
                chrs.pop();
            } else {
                return false;
            }
        }
        return chrs.empty();
    }
};

int main(int argc, char* argv[])
{
    std::string s = "{[()]}";
    bool is_valid = Solution().isValid(s);
    printf("Input: %s\n", s.c_str());
    printf("Output: %s\n", (is_valid ? "true" : "false"));
    return 0;
}
