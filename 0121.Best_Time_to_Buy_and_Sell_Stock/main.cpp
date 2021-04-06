#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(vector<int>& prices){
  std::cout << "Input: prices = " << toString(prices) << std::endl;
  Solution solver;
  int ans = solver.maxProfit(prices);
  std::cout << "Output: " << ans << std::endl << std::endl;
}

int main(){
  vector<int> prices = {7,1,5,3,6,4};

  runSample(prices);

  return 0;
}