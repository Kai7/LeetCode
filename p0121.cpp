#include "utils/data_structure.hpp"

#define MAX(a,b) (((a)>(b))?(a):(b))

class Solution {
public:
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

};