#include "solver.hpp"

void runSample(int n){
  Solution solver;
  int ans = solver.numTrees(n);
  std::cout << "Input: n = " << n << std::endl;
  std::cout << "Output: " << ans << std::endl << std::endl;
}

int main(){
  runSample(1);
  runSample(2);
  runSample(3);
  runSample(4);
  runSample(10);
  runSample(19);
  return 0;
}