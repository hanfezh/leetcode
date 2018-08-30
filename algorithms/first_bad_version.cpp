/*
 * =====================================================================================
 *
 *       Filename:  first_bad_version.cpp
 *
 *    Description:  First Bad Version: You are a product manager and currently leading a 
 *                  team to develop a new product. Unfortunately, the latest version of 
 *                  your product fails the quality check. Since each version is 
 *                  developed based on the previous version, all the versions after a 
 *                  bad version are also bad.
 *
 *        Version:  1.0
 *        Created:  08/30/18 11:23:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version)
{
    return version >= 4 ? true : false;
}

class Solution
{
public:
    int firstBadVersion(int n)
    {
        while (isBadVersion(n))
        {
            n--;
        }
        while (!isBadVersion(n))
        {
            n++;
        }

        return n;
    }
};

int main(int argc, char* argv[])
{
    int bad_ver = Solution().firstBadVersion(10);
    printf("%d\n", bad_ver);
    return 0;
}
