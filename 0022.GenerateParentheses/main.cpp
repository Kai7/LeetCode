#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(int n){
  std::cout << "Input: n = " << n << std::endl;
  Solution solver;
  vector<string> ans = solver.generateParenthesis(n);
  std::cout << "Output: " << toString(ans) << std::endl << std::endl;
}

int main() {
  runSample(1);
  runSample(2);
  runSample(3);
  runSample(4);
  runSample(5);
  runSample(6);
  // runSample(7);
  // runSample(8);

  return 0;
}