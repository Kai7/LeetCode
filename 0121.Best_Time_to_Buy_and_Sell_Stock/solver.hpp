#include "utils/data_structure.hpp"
#include <iostream>
#include "stdio.h"

#define MAX(a,b) (((a)>(b))?(a):(b))

class Solution {
public:
  /* Accepted: 94.28, 73.25 */
  int maxProfit(vector<int>& prices){
    if(prices.size() <= 1) return 0;
    int min_price = prices[0];
    int max_profit = 0;
    for (size_t i = 1; i < prices.size(); i++){
      if (prices[i] < min_price){
        min_price = prices[i];
      } else {
        max_profit = MAX(max_profit, prices[i] - min_price);
      }
    }
    return max_profit;
  }

#if 0
  /* Time Limit Exceeded */
  int maxProfit(vector<int>& prices){
    if(prices.size() <= 1) return 0;
    int max_profit = 0;
    for (size_t i = 0; i < prices.size() - 1; i++){
      for (size_t j = i+1; j < prices.size(); j++){
        if(prices[j] - prices[i] > max_profit) max_profit = prices[j] - prices[i];
      }
    }
    return max_profit;
  }
#endif
};