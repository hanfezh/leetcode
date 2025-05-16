/*
 * =====================================================================================
 *
 *       Filename:  time_map.cpp
 *
 *    Description:  981. Time Based Key-Value Store
 *                  https://leetcode.com/problems/time-based-key-value-store/
 *
 *        Version:  1.0
 *        Created:  05/16/2025 13:50:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <map>
#include <string>
#include <unordered_map>

#include "gtest/gtest.h"

class TimeMap {
 public:
  TimeMap() {}

  void set(std::string key, std::string value, int timestamp) { values_[key][timestamp] = value; }

  std::string get(std::string key, int timestamp) {
    const auto iter = values_.find(key);
    if (iter == values_.end()) {
      return "";
    }

    const auto& time_values = iter->second;
    auto time_iter = time_values.upper_bound(timestamp);  // >
    if (time_iter == time_values.begin()) {
      return "";
    }
    time_iter--;  // <=
    return time_iter->second;
  }

 private:
  std::unordered_map<std::string, std::map<int, std::string>> values_;
};

TEST(Solution, TimeMap) {
  TimeMap* obj = new TimeMap();

  obj->set("foo", "bar", 1);
  EXPECT_EQ(obj->get("foo", 1), "bar");
  EXPECT_EQ(obj->get("foo", 3), "bar");

  obj->set("foo", "bar2", 4);
  EXPECT_EQ(obj->get("foo", 4), "bar2");
  EXPECT_EQ(obj->get("foo", 5), "bar2");
}
