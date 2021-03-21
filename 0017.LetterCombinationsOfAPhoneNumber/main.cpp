#include "solver.hpp"
#include "utils/utils.hpp"

void runSample(string digits){
  Solution solver;
  vector<string> ans = solver.letterCombinations(digits);
  std::cout << "Input: digits = " << addQuotationMark(digits) << std::endl;
  std::cout << "Output: " << toString(ans) << std::endl << std::endl;
}

int main(){
  // runSample("");
  // runSample("2");
  runSample("23");

  return 0;
}