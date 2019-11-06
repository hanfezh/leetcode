// =====================================================================================
//
//       Filename:  binary_search.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  11/05/2019 01:14:29 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <vector>

class Solution
{
public:
    int search(std::vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (nums[middle] < target)
            {
                left = middle + 1;
            }
            else if (nums[middle] > target)
            {
                right = middle - 1;
            }
            else
            {
                // nums[middle] == target
                return middle;
            }
        }

        return -1;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    int index = Solution().search(nums, target);
    printf("Found %d? %d\n", target, index);
    return 0;
}
