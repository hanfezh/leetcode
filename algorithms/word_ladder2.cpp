// =====================================================================================
//
//       Filename:  word_ladder2.cpp
//
//    Description:  126. Word Ladder II.
//
//        Version:  1.0
//        Created:  08/21/2019 04:31:52 PM
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
#include <utility>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<vector<string>> findLadders(const string& begin_word, const string& end_word, vector<string>& word_list)
    {
        unordered_set<string> words(word_list.begin(), word_list.end());
        vector<pair<string, int>> bfs_queue;
        vector<int> found_list;
        int index = 0;

        // Push first node
        bfs_queue.push_back(make_pair(begin_word, -1));

        // Breadth first search
        while (index < bfs_queue.size())
        {
            int bfs_size = bfs_queue.size();
            for (int k = index; k < bfs_size; k++)
            {
                const auto& item = bfs_queue[k];
                string node = item.first;

                if (node == end_word)
                {
                    // Found desitination
                    found_list.push_back(k);
                }

                // Erase node from set, mark as visited
                words.erase(node);

                // Try to find all adjacent node
                for (int i = 0; i < node.size(); i++)
                {
                    // Keep original char
                    char c = node[i];

                    // Traverse letter a~z
                    for (char j = 'a'; j <= 'z'; j++)
                    {
                        node[i] = j;
                        if (words.count(node) > 0)
                        {
                            // Found adjacent node
                            bfs_queue.push_back(make_pair(node, k));
                        }
                    }

                    // Recover orignal char
                    node[i] = c;
                }
            }

            if (!found_list.empty())
            {
                break;
            }

            index = bfs_size;
        }

        // Collect ladders
        vector<vector<string>> ladders;
        for (auto idx: found_list)
        {
            int pre = idx;
            int cur = ladders.size();
            ladders.push_back(vector<string>());

            while (pre != -1)
            {
                ladders[cur].insert(ladders[cur].begin(), bfs_queue[pre].first);
                pre = bfs_queue[pre].second;
            }
        }

        return ladders;
    }
};

int main(int argc, char* argv[])
{
    vector<string> word_list = {"hot", "dot", "dog", "lot", "log", "cog"};
    auto ladders = Solution().findLadders("hit", "cog", word_list);
    for (const auto& item: ladders)
    {
        for (const auto& node: item)
        {
            printf("%s ", node.c_str());
        }
        printf("\n");
    }
    return 0;
}
