// =====================================================================================
//
//       Filename:  excel_sheet_column_title.cpp
//
//    Description:  168. Excel Sheet Column Title. Given a positive integer, return its 
//                  corresponding column title as appear in an Excel sheet.
//
//        Version:  1.0
//        Created:  09/16/2019 07:14:26 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <stdlib.h>
#include <string>

class Solution
{
public:
    std::string convertToTitle(int n)
    {
        const int kLetterCnt = 'Z' - 'A' + 1;
        if (n <= kLetterCnt)
        {
            return std::string() + (char)(n + 'A' - 1);
        }

        n--;
        return convertToTitle(n / kLetterCnt) + convertToTitle(n % kLetterCnt + 1);
    }
};

int main(int argc, char* argv[])
{
    int num = 701;
    if (argc > 1)
    {
        num = atoi(argv[1]);
    }

    std::string title = Solution().convertToTitle(num);
    printf("%d -> %s\n", num, title.c_str());
    return 0;
}
