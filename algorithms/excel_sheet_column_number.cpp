/*
 * =====================================================================================
 *
 *       Filename:  excel_sheet_column_number.cpp
 *
 *    Description:  171. Excel Sheet Column Number
 *                  https://leetcode.com/problems/excel-sheet-column-number/
 *
 *        Version:  1.0
 *        Created:  02/22/2022 11:47:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <cstdio>
#include <string>

class Solution {
 public:
  int titleToNumber(const std::string& title) {
    int num = 0;
    for (const char c : title) {
      num = num * 26 + (c - 'A' + 1);
    }
    return num;
  }
};

int main(int argc, char* argv[]) {
  std::string title = "AA";
  if (argc > 1) {
    title = argv[1];
  }
  const int num = Solution().titleToNumber(title);
  printf("columnTitle = %s\n", title.c_str());
  printf("%d\n", num);
  return 0;
}
