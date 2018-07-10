/*
 * =====================================================================================
 *
 *       Filename:  generate_parentheses.cpp
 *
 *    Description:  Generate Parentheses: Given n pairs of parentheses, write a function 
 *                  to generate all combinations of well-formed parentheses.
 *
 *        Version:  1.0
 *        Created:  07/10/18 09:00:59
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
#include <vector>

class Solution
{
public:
    std::vector<std::string> generateParenthesis(int n)
    {
        std::vector<std::string> pa_list;
        generateParenthesis(n, 0, "", &pa_list);
        return pa_list;
    }

private:
    void generateParenthesis(int num, int cnt, const std::string& pa_item, std::vector<std::string>* pa_list)
    {
        if (pa_item.size() == (2 * num))
        {
            pa_list->push_back(pa_item);
            return;
        }

        if (cnt < num)
        {
            generateParenthesis(num, cnt + 1, pa_item + "(", pa_list);
            if (2 * cnt > pa_item.size())
            {
                generateParenthesis(num, cnt, pa_item + ")", pa_list);
            }
        }
        else
        {
            // cnt == num
            generateParenthesis(num, cnt, pa_item + ")", pa_list);
        }
    }
};

int main(int argc, char* argv[])
{
    int num = 3;
    if (argc > 1)
    {
        num = atoi(argv[1]);
    }

    auto pa_list = Solution().generateParenthesis(num);
    for (const auto& item: pa_list)
    {
        printf("%s\n", item.c_str());
    }

    return 0;
}
