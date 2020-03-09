// 1366. Rank Teams by Votes: https://leetcode.com/problems/rank-teams-by-votes
// Author: xianfeng.zhu@gmail.com

#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    string rankTeams(const vector<string>& votes)
    {
        const int chr_size = 26;
        vector<vector<int>> counts(chr_size, vector<int>(chr_size + 1, 0));
        for (const auto chr: votes[0])
        {
            counts[chr - 'A'][chr_size] = chr;
        }
        for (const auto& vote: votes)
        {
            for (int i = 0; i < vote.size(); i++)
            {
                counts[vote[i] - 'A'][i] -= 1;
            }
        }

        // Sort votes
        std::sort(counts.begin(), counts.end());

        string rank;
        for (const auto& row: counts)
        {
            if (row[chr_size] != 0)
            {
                rank += (char)row[chr_size];
            }
        }

        return rank;
    }
};

int main(int argc, char* argv[])
{
    vector<string> votes = {"BCA", "CAB", "CBA", "ABC", "ACB", "BAC"};
    string rank = Solution().rankTeams(votes);
    printf("Output: %s\n", rank.c_str());
    return 0;
}
