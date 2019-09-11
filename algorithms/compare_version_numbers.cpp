// =====================================================================================
//
//       Filename:  compare_version_numbers.cpp
//
//    Description:  165. Compare Version Numbers.
//
//        Version:  1.0
//        Created:  09/11/2019 01:16:30 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <string>

class Solution
{
public:
    int compareVersion(std::string& version1, std::string& version2)
    {
        int index1 = 0;
        int index2 = 0;
        int minor1 = 0;
        int minor2 = 0;

        while (index1 < version1.size() || index2 < version2.size())
        {
            while (index1 < version1.size() && version1[index1] != '.')
            {
                minor1 = minor1 * 10 + (version1[index1] - '0');
                index1++;
            }

            while (index2 < version2.size() && version2[index2] != '.')
            {
                minor2 = minor2 * 10 + (version2[index2] - '0');
                index2++;
            }

            if (minor1 < minor2)
            {
                return -1;
            }
            else if (minor1 > minor2)
            {
                return 1;
            }

            // minor1 == minor2
            minor1 = 0;
            minor2 = 0;
            index1++;
            index2++;
        }

        return 0;
    }
};

int main(int argc, char* argv[])
{
    std::string version1 = "7.5.2.4";
    std::string version2 = "7.5.3";
    if (argc > 2)
    {
        version1 = argv[1];
        version2 = argv[2];
    }

    int ret = Solution().compareVersion(version1, version2);
    printf("%s vs %s -> %d\n", version1.c_str(), version2.c_str(), ret);
    return 0;
}
