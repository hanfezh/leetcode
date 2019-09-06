// =====================================================================================
//
//       Filename:  word_break2.cpp
//
//    Description:  140. Word Break II.
//                  Given a non-empty string s and a dictionary wordDict containing a 
//                  list of non-empty words, add spaces in s to construct a sentence 
//                  where each word is a valid dictionary word. Return all such possible 
//                  sentences.
//
//        Version:  1.0
//        Created:  09/04/2019 06:24:49 PM
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
#include <unordered_map>

using namespace std;

// DFS, time limit exceeded
class Solution1
{
public:
    vector<string> wordBreak(string& s, vector<string>& word_dict)
    {
        unordered_set<string> word_set(word_dict.begin(), word_dict.end());
        vector<string> sentences;
        string current;
        dfsTraverse(s, word_set, 0, &current, &sentences);
        return sentences;
    }

private:
    void dfsTraverse(const string& s, const unordered_set<string>& word_set, 
        int start, string* current, vector<string>* sentences)
    {
        if (start == s.size())
        {
            sentences->push_back(*current);
            return;
        }

        for (int i = start; i < s.size(); i++)
        {
            auto seg = s.substr(start, i - start + 1);
            if (word_set.count(seg) > 0)
            {
                auto index = current->size();
                if (current->size() > 0)
                {
                    current->push_back(' ');
                }
                current->insert(current->size(), seg);
                dfsTraverse(s, word_set, i + 1, current, sentences);
                current->erase(index);
            }
        }
    }
};

// DFS & DP, accepted
class Solution2
{
public:
    vector<string> wordBreak(string& s, vector<string>& word_dict)
    {
        unordered_set<string> word_set(word_dict.begin(), word_dict.end());
        unordered_map<int, vector<string>> sentences;
        sentences[s.size()].push_back("");
        dfsTraverse(s, word_set, 0, sentences);
        return sentences[0];
    }

private:
    void dfsTraverse(const string& s, const unordered_set<string>& word_set, 
        int start, unordered_map<int, vector<string>>& sentences)
    {
        if (start == s.size() || sentences.count(start) > 0)
        {
            return;
        }

        for (const auto& word: word_set)
        {
            if ((start + word.size() > s.size()) ||
                (s.substr(start, word.size()) != word))
            {
                continue;
            }

            dfsTraverse(s, word_set, start + word.size(), sentences);

            for (const auto& item: sentences[start + word.size()])
            {
                sentences[start].push_back(item.empty() ? word : (word + " " + item));
            }
        }
    }
};

using Solution = Solution2;

int main(int argc, char* argv[])
{
    string s = "aaaaaaa";
    vector<string> word_dict = {"aaaa", "aaa"};
    auto sentences = Solution().wordBreak(s, word_dict);
    printf("Found? %s\n", (sentences.size() > 0 ? "true" : "false"));
    for (auto& item: sentences)
    {
        printf("%s\n", item.c_str());
    }
    return 0;
}
