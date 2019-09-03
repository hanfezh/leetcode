// =====================================================================================
//
//       Filename:  word_break.cpp
//
//    Description:  139. Word Break. 
//                  Given a non-empty string s and a dictionary wordDict containing a 
//                  list of non-empty words, determine if s can be segmented into a 
//                  space-separated sequence of one or more dictionary words.
//
//        Version:  1.0
//        Created:  09/03/2019 06:40:20 PM
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
#include <unordered_set>

using namespace std;

// DFS, time limit exceeded
class Solution1
{
public:
    bool wordBreak(string& s, vector<string>& word_dict)
    {
        unordered_set<string> word_set(word_dict.begin(), word_dict.end());
        bool found = false;
        dfsTraverse(s, word_set, 0, &found);
        return found;
    }

private:
    void dfsTraverse(const string& s, const unordered_set<string>& word_set, int start, bool* found)
    {
        if (start == s.size())
        {
            *found = true;
            return;
        }

        for (int i = start; i < s.size(); i++)
        {
            auto seg = s.substr(start, i - start + 1);
            if (word_set.count(seg) > 0)
            {
                dfsTraverse(s, word_set, i + 1, found);
            }
            if (*found)
            {
                break;
            }
        }
    }
};

// DP, accepted
class Solution2
{
public:
    bool wordBreak(string& s, vector<string>& word_dict)
    {
        vector<bool> dp(s.size() + 1, false);

        // Initial first as true
        dp[0] = true;

        for (int i = 0; i < s.size(); i++)
        {
            if (!dp[i])
            {
                // Can't split
                continue;
            }

            for (const auto& word: word_dict)
            {
                int len = word.size();
                if (i + len > s.size())
                {
                    continue;
                }

                if (s.substr(i, len) != word)
                {
                    continue;
                }

                dp[i + len] = true;
            }
        }

        return dp.back();
    }
};

using Solution = Solution2;

int main(int argc, char* argv[])
{
    string s = "leetcode";
    vector<string> word_dict = {"leet", "code"};
    bool found = Solution().wordBreak(s, word_dict);
    printf("Found? %s\n", (found ? "true" : "false"));
    return 0;
}
