// =====================================================================================
//
//       Filename:  substring_with_concatenation_words.cpp
//
//    Description:  30. Substring with Concatenation of All Words.
//
//        Version:  1.0
//        Created:  09/27/2019 05:25:25 PM
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
#include <unordered_map>

class Solution
{
public:
    std::vector<int> findSubstring(std::string& s, std::vector<std::string>& words)
    {
        if (s.empty() || words.empty() || words[0].empty())
        {
            return std::vector<int>();
        }

        std::unordered_map<std::string, int> sources;
        for (const auto& item: words)
        {
            sources[item]++;
        }

        std::vector<int> indices;
        int num = words.size();
        int len = words[0].size();

        for (int i = 0; i <= (int)(s.size() - (num * len)); i++)
        {
            int j = 0;
            std::unordered_map<std::string, int> visited;
            for ( ; j < num; j++)
            {
                auto word = s.substr(i + j * len, len);
                auto iter = sources.find(word);
                if (iter == sources.end())
                {
                    break;
                }

                visited[word]++;
                if (visited[word] > iter->second)
                {
                    break;
                }
            }

            if (j == num)
            {
                indices.push_back(i);
            }
        }

        return indices;
    }
};

int main(int argc, char* argv[])
{
    std::string s = "wordgoodgoodgoodbestword";
    std::vector<std::string> words = {"word", "good", "best", "good"};
    auto indices = Solution().findSubstring(s, words);
    printf("Find result:[");
    for (int i = 0; i < indices.size(); i++)
    {
        printf("%s%d", (i != 0 ? ", " : ""), indices[i]);
    }
    printf("]\n");
    return 0;
}
