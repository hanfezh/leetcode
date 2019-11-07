// =====================================================================================
//
//       Filename:  find_k_closest_elements.cpp
//
//    Description:  658. Find K Closest Elements.
//                  Given a sorted array, two integers k and x, find the k closest 
//                  elements to x in the array. The result should also be sorted in 
//                  ascending order. If there is a tie, the smaller elements are always 
//                  preferred.
//
//        Version:  1.0
//        Created:  11/07/2019 06:48:19 PM
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

class Solution
{
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        int left = 0;
        int right = arr.size() - 1;
        int index = -1;
        int found = 0;

        // Try to find x
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] > x)
            {
                right = mid;
            }
            else if (arr[mid] < x)
            {
                left = mid + 1;
            }
            else
            {
                // Found x
                index = mid;
                found = 1;
                break;
            }
        }

        if (left == right)
        {
            // Not found, and left/right is the index to be inserted
            index = left;
        }

        left = std::max(index - (k - found), 0);
        right = std::min(index + (k - found), (int)(arr.size() - 1));

        while ((right - left) > (k - 1))
        {
            if ((x - arr[left]) <= (arr[right] - x))
            {
                right--;
            }
            else
            {
                left++;
            }
        }

        return vector<int>(arr.begin() + left, arr.begin() + right + 1);
    }
};

int main(int argc, char* argv[])
{
    vector<int> arr = {0, 0, 1, 2, 3, 3, 4, 7, 7, 8};
    int k = 3;
    int x = 5;
    auto nums = Solution().findClosestElements(arr, k, x);
    for (auto n: nums)
    {
        printf("%d ", n);
    }
    printf("\n");
    return 0;
}
