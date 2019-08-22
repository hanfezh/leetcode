// =====================================================================================
//
//       Filename:  longest_consecutive_sequence.cpp
//
//    Description:  128. Longest Consecutive Sequence. Given an unsorted array of 
//                  integers, find the length of the longest consecutive elements 
//                  sequence. Your algorithm should run in O(n) complexity.
//
//        Version:  1.0
//        Created:  08/21/2019 09:09:21 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int max_count = 0;
        for (const auto& n: nums)
        {
            // Lower adjacent
            int adjacent = n;
            int cur_count = 0;
            while (num_set.erase(adjacent) != 0)
            {
                cur_count++;
                adjacent--;
            }

            // Upper adjacent
            adjacent = n + 1;
            while (num_set.erase(adjacent) != 0)
            {
                cur_count++;
                adjacent++;
            }

            if (cur_count > max_count)
            {
                max_count = cur_count;
            }
        }

        return max_count;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int longest = Solution().longestConsecutive(nums);
    printf("Longest consecutive sequence: %d\n", longest);
}
