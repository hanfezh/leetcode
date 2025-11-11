/*
 * =====================================================================================
 *
 *       Filename:  attendance_record1.cpp
 *
 *    Description:  551. Student Attendance Record I
 *
 *        Version:  1.0
 *        Created:  11/11/2025 18:26:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <string>
#include <utility>
#include <vector>

#include "gtest/gtest.h"

class Solution {
 public:
  bool checkRecord(std::string s) {
    const int n = s.length();
    int count_a = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'A' && ++count_a >= 2) {
        return false;
      }
      if (i > 1 && s[i] == 'L' && s[i - 1] == 'L' && s[i - 2] == 'L') {
        return false;
      }
    }
    return true;
  }
};

TEST(Solution, checkRecord) {
  std::vector<std::pair<std::string, bool>> cases = {
      {"PPALLP", true},
      {"PPALLL", false},
      {"ALLAPPL", false},
  };
  for (auto& [s, res] : cases) {
    EXPECT_EQ(Solution().checkRecord(s), res);
  }
}
