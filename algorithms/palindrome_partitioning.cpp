// =====================================================================================
//
//       Filename:  palindrome_partitioning.cpp
//
//    Description:  131. Palindrome Partitioning.
//
//        Version:  1.0
//        Created:  08/30/2019 11:36:22 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    vector<vector<string>> partition(string& str)
    {
        vector<vector<string>> groups;
        vector<string> current;
        dfsTraverse(str, 0, &current, &groups);
        return groups;
    }

private:
    void dfsTraverse(const string& str, int start, 
        vector<string>* current, vector<vector<string>>* groups)
    {
        if (start == str.size())
        {
            groups->push_back(*current);
            return;
        }

        for (int i = start; i < str.size(); i++)
        {
            if (isPalindrome(str, start, i))
            {
                current->push_back(str.substr(start, i - start + 1));
                dfsTraverse(str, i + 1, current, groups);
                current->pop_back();
            }
        }
    }

    bool isPalindrome(const string& str, int start, int end)
    {
        while (end > start)
        {
            if (str[start] != str[end])
            {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
};

int main(int argc, char* argv[])
{
    string str = "aab";
    if (argc > 2)
    {
        str = argv[1];
    }

    auto groups = Solution().partition(str);
    for (const auto& group: groups)
    {
        for (const auto& item: group)
        {
            printf("%s ", item.c_str());
        }
        printf("\n");
    }

    return 0;
}
