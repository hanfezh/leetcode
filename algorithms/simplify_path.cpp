/*
 * =====================================================================================
 *
 *       Filename:  simplify_path.cpp
 *
 *    Description:  71. Simplify Path. Given an absolute path for a file (Unix-style), 
 *                  simplify it. Or in other words, convert it to the canonical path.
 *
 *        Version:  1.0
 *        Created:  04/11/19 10:39:34
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
    std::string simplifyPath(const std::string& path)
    {
        std::vector<std::string> nodes;
        size_t idx = 0;
        while (idx < path.size())
        {
            size_t pos = path.find('/', idx);
            std::string sub;
            if (pos == std::string::npos)
            {
                sub = path.substr(idx);
            }
            else
            {
                sub = path.substr(idx, pos - idx);
            }

            if (sub.empty() || sub == ".")
            {
                ; // Ignore
            }
            else if (sub == "..")
            {
                if (!nodes.empty())
                {
                    nodes.pop_back();
                }
            }
            else
            {
                nodes.push_back(sub);
            }

            if (pos == std::string::npos)
            {
                break;
            }
            idx = pos + 1;
        }

        std::string simp_path;
        for (const auto& item: nodes)
        {
            simp_path += "/" + item;
        }
        if (simp_path.empty())
        {
            simp_path = "/";
        }
        return simp_path;
    }
};

int main(int argc, char* argv[])
{
    std::string path = "/a//b////c/d//././/..";
    auto simp_path = Solution().simplifyPath(path);
    printf("Simplify path: %s\n", simp_path.c_str());
    return 0;
}
