#include "utils/data_structure.hpp"
#include <iostream>
#include "stdio.h"

class Solution {
public:
  /* Accepted: 39.46, 26.76 */
  int maxProfit(vector<int>& prices){
    if(prices.size() <= 1) return 0;
    int profit = 0;
    size_t buy_day = 0;
    size_t cell_day = 0;
    size_t look_day = 1;
    while(look_day < prices.size()){
      while (look_day < prices.size() && prices[look_day] <= prices[buy_day]){
        buy_day = look_day;
        look_day += 1;
      }
      if (look_day >= prices.size()) break;
      cell_day = look_day;
      while (look_day < prices.size() && prices[look_day] >= prices[cell_day]){
        cell_day = look_day;
        look_day += 1;
      }
      profit += prices[cell_day] - prices[buy_day];
      printf("buy: %lu, cell: %lu, profit: %d\n", buy_day, cell_day, prices[cell_day] - prices[buy_day]);
      buy_day = look_day;
    }
    return profit;
  }

};