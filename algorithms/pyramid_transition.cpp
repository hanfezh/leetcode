/*
 * =====================================================================================
 *
 *       Filename:  pyramid_transition.cpp
 *
 *    Description:  756. Pyramid Transition Matrix
 *
 *        Version:  1.0
 *        Created:  01/02/2026 11:03:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Michael Zhu (), xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <map>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  bool pyramidTransition(string bottom, vector<string>& allowed) {
    map<pair<char, char>, vector<char>> allowed_map;
    for (const auto& s : allowed) {
      allowed_map[{s[0], s[1]}].push_back(s[2]);
    }

    set<string> visited;
    std::function<bool(const string&, const string&, int)> backtrack =
        [&](const string& bottom, const string& row, int i) -> bool {
      if (bottom.length() == 1) {
        return true;
      }
      if (i == bottom.length()) {
        if (visited.count(bottom) > 0) {
          return false;
        }
        return backtrack(row, "", 1);
      }

      const auto& m = allowed_map[{bottom[i - 1], bottom[i]}];
      for (const char c : m) {
        if (backtrack(bottom, row + c, i + 1)) {
          return true;
        }
      }
      return false;
    };

    return backtrack(bottom, "", 1);
  }
};

TEST(Solution, pyramidTransition) {
  vector<tuple<string, vector<string>, bool>> cases = {
      {"BCD", {"BCC", "CDE", "CEA", "FFF"}, true},
      {"AAAA", {"AAB", "AAC", "BCD", "BBE", "DEF"}, false},
  };
  for (auto& [bottom, allowed, res] : cases) {
    EXPECT_EQ(Solution().pyramidTransition(bottom, allowed), res);
  }
}
