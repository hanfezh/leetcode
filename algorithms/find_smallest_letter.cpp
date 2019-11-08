// =====================================================================================
//
//       Filename:  find_smallest_letter.cpp
//
//    Description:  744. Find Smallest Letter Greater Than Target.
//
//        Version:  1.0
//        Created:  11/08/2019 06:42:33 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <vector>

using std::vector;

class Solution
{
public:
    char nextGreatestLetter(vector<char>& letters, char target)
    {
        int left = 0;
        int right = letters.size() - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (letters[mid] <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        if (letters[left] > target)
        {
            return letters[left];
        }
        return letters[(left + 1) % letters.size()];
    }
};

int main(int argc, char* argv[])
{
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'k';
    char smallest = Solution().nextGreatestLetter(letters, target);
    printf("Smallest letter is '%c'\n", smallest);
    return 0;
}
