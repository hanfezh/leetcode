// =====================================================================================
//
//       Filename:  find_kth_smallest_pair_distance.cpp
//
//    Description:  719. Find K-th Smallest Pair Distance. 
//                  Given an integer array, return the k-th smallest distance among all 
//                  the pairs. The distance of a pair (A, B) is defined as the absolute 
//                  difference between A and B.
//
//        Version:  1.0
//        Created:  11/13/2019 06:47:49 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <algorithm>
#include <vector>

using std::vector;

// Binary search
class Solution
{
public:
    int smallestDistancePair(vector<int>& nums, int k)
    {
        // Sort array
        std::sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.back() - nums.front();

        while (left < right)
        {
            int count = 0;
            int middle = (left + right) / 2;

            for (int i = 0, j = 0; i < nums.size(); i++)
            {
                while (j < nums.size() && (nums[j] - nums[i]) <= middle)
                {
                    j++;
                }
                count += j - i - 1;
            }

            if (count < k)
            {
                left = middle + 1;
            }
            else
            {
                right = middle;
            }
        }

        return left;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {1, 3, 1};
    int k = 1;
    int d = Solution().smallestDistancePair(nums, k);
    printf("Smallest distance is %d\n", d);
    return 0;
}
