/*
 * =====================================================================================
 *
 *       Filename:  stock_price.cpp
 *
 *    Description:  2034. Stock Price Fluctuation
 *
 *        Version:  1.0
 *        Created:  11/17/2025 10:15:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <map>
#include <set>
#include <utility>

class StockPrice {
 public:
  StockPrice() {}

  void update(int timestamp, int price) {
    auto it = price_records_.find(timestamp);
    if (it != price_records_.end()) {
      ordered_prices_.erase({it->second, timestamp});
      it->second = price;
    } else {
      price_records_[timestamp] = price;
    }
    ordered_prices_.insert({price, timestamp});
  }

  int current() {
    if (price_records_.empty()) {
      return 0;
    }
    return price_records_.rbegin()->second;
  }

  int maximum() {
    if (ordered_prices_.empty()) {
      return 0;
    }
    return ordered_prices_.rbegin()->first;
  }

  int minimum() {
    if (ordered_prices_.empty()) {
      return 0;
    }
    return ordered_prices_.begin()->first;
  }

 private:
  std::map<int, int> price_records_;              // timestamp -> price, sorted by timestamp
  std::set<std::pair<int, int>> ordered_prices_;  // sorted by {price, timestamp}
};
