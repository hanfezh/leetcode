// =====================================================================================
//
//       Filename:  find_peak_element.cpp
//
//    Description:  162. Find Peak Element.
//
//        Version:  1.0
//        Created:  09/12/2019 09:59:46 AM
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
    int findPeakElement(std::vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[mid + 1])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    int idx = Solution().findPeakElement(nums);
    printf("Index of one peak element: %d\n", idx);
    return 0;
}
