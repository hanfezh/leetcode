/*
 * =====================================================================================
 *
 *       Filename:  find_all_recipes.cpp
 *
 *    Description:  2115. Find All Possible Recipes from Given Supplies
 *
 *        Version:  1.0
 *        Created:  11/13/2025 22:54:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

class Solution {
 public:
  std::vector<std::string> findAllRecipes(std::vector<std::string>& recipes,
                                          std::vector<std::vector<std::string>>& ingredients,
                                          std::vector<std::string>& supplies) {
    std::unordered_map<std::string, int> indexes;
    for (int i = 0; i < recipes.size(); i++) {
      indexes[recipes[i]] = i;
    }
    std::unordered_map<std::string, bool> cookable;
    for (auto& s : supplies) {
      cookable[s] = true;
    }

    std::function<bool(const std::string&)> dfs = [&](const std::string& r) -> bool {
      auto it1 = cookable.find(r);
      if (it1 != cookable.end()) {
        return it1->second;
      }

      auto it2 = indexes.find(r);
      if (it2 == indexes.end()) {
        return false;
      }

      const int i = it2->second;
      cookable[r] = false;

      for (auto& ingr : ingredients[i]) {
        if (!dfs(ingr)) {
          return false;
        }
      }
      cookable[r] = true;
      return true;
    };

    std::vector<std::string> res;
    for (auto& r : recipes) {
      if (dfs(r)) {
        res.push_back(r);
      }
    }
    return res;
  }
};

TEST(Solution, findAllRecipes) {
  std::vector<std::tuple<std::vector<std::string>, std::vector<std::vector<std::string>>,
                         std::vector<std::string>, std::vector<std::string>>>
      cases = {
          {{"bread"}, {{"yeast", "flour"}}, {"yeast", "flour", "corn"}, {"bread"}},
          {{"bread", "sandwich"},
           {{"yeast", "flour"}, {"bread", "meat"}},
           {"yeast", "flour", "meat"},
           {"bread", "sandwich"}},
          {{"bread", "sandwich", "burger"},
           {{"yeast", "flour"}, {"bread", "meat"}, {"sandwich", "meat", "bread"}},
           {"yeast", "flour", "meat"},
           {"bread", "sandwich", "burger"}},
      };
  for (auto& [recipes, ingredients, supplies, res] : cases) {
    EXPECT_THAT(Solution().findAllRecipes(recipes, ingredients, supplies),
                testing::UnorderedElementsAreArray(res));
  }
}
