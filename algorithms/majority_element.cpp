// =====================================================================================
//
//       Filename:  majority_element.cpp
//
//    Description:  169. Majority Element.
//
//        Version:  1.0
//        Created:  09/19/2019 08:39:09 PM
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

class Solution
{
public:
    int majorityElement(std::vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int element = Solution().majorityElement(nums);
    printf("Majority element is %d\n", element);
    return 0;
}
