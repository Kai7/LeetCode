#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(int m, int n) {
  std::cout << "Input: m = " << m << ", n = " << n << std::endl;
  Solution solver;
  int ans = solver.uniquePaths(m, n);
  std::cout << "Output: " << ans << std::endl << std::endl;
}

int main(){
  // runSample(2, 3);
  // runSample(3, 3);
  // runSample(7, 3);
  // runSample(3, 7);
  runSample(10, 10);
  return 0;
}