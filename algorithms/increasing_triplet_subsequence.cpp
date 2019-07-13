/*
 * =====================================================================================
 *
 *       Filename:  increasing_triplet_subsequence.cpp
 *
 *    Description:  334. Increasing Triplet Subsequence.
 *                  Given an unsorted array return whether an increasing subsequence of 
 *                  length 3 exists or not in the array.
 *
 *        Version:  1.0
 *        Created:  07/13/2019 10:01:36 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <vector>

using std::vector;

class Solution
{
public:
    bool increasingTriplet(vector<int>& nums)
    {
        int first = INT_MAX;
        int second = INT_MAX;
        for (auto n: nums)
        {
            if (n <= first)
            {
                first = n;
            }
            else if (n <= second)
            {
                second = n;
            }
            else
            {
                // Found
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {10, 1, 9, 2, 6, 3};
    auto found = Solution().increasingTriplet(nums);
    printf("Found? %s\n", (found ? "Yes" : "No"));
    return 0;
}
