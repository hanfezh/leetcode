// =====================================================================================
//
//       Filename:  distinct_subsequences.cpp
//
//    Description:  115. Distinct Subsequences.
//
//        Version:  1.0
//        Created:  08/13/2019 09:56:38 PM
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

// Time limit exceeded
class Solution1
{
public:
    int numDistinct(const string& s, const string& t)
    {
        vector<bool> visited(s.size(), false);
        string current;
        int sum = 0;
        dfsPermute(s, t, 0, &current, &visited, &sum);
        return sum;
    }

private:
    void dfsPermute(const string& s, const string& t, int idx,
        string* current, vector<bool>* visited, int* sum)
    {
        if (s.size() < t.size())
        {
            *sum = 0;
            return;
        }
        else if (current->size() == t.size())
        {
            // printf("%s\n", current->c_str());
            *sum += 1;
            return;
        }

        for (int i = idx; i < s.size(); i++)
        {
            if (visited->at(i))
            {
                continue;
            }
            if (s[i] != t[current->size()])
            {
                continue;
            }

            visited->at(i) = true;
            current->push_back(i + '0');
            dfsPermute(s, t, i + 1, current, visited, sum);
            current->erase(current->size() - 1);
            visited->at(i) = false;
        }
    }
};

class Solution2
{
public:
    int numDistinct(const string& s, const string& t)
    {
        vector<vector<long>> dp(t.size() + 1, vector<long>(s.size() + 1, 0));
        for (int i = 0; i <= s.size(); i++)
        {
            dp[0][i] = 1;
        }

        for (int i = 0; i < t.size(); i++)
        {
            for (int j = 0; j < s.size(); j++)
            {
                if (s[j] == t[i])
                {
                    dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j];
                }
                else
                {
                    dp[i + 1][j + 1] = dp[i + 1][j];
                }
            }
        }

        return dp[t.size()][s.size()];
    }
};

using Solution = Solution2;

int main(int argc, char* argv[])
{
    string s = "rabbbit";
    string t = "rabbit";
    if (argc > 2)
    {
        s = argv[1];
        t = argv[2];
    }
    int sum = Solution().numDistinct(s, t);
    printf("%s, %s -> %d\n", s.c_str(), t.c_str(), sum);
    return 0;
}
