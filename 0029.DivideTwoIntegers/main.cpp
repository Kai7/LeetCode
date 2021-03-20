#include "solver.hpp"

void runSample(int dividend, int divisor) {
  Solution solver;
  std::cout << "Input: dividend = " << dividend << ", divisor = " << divisor << std::endl;
  int ans = solver.divide(dividend, divisor);
  std::cout << "Output: " << ans << std::endl << std::endl;
}

int main(){
  runSample(10, 3);
  runSample(7, -3);
  runSample(-10, 3);
  runSample(-7, -3);
  runSample(1, 1);
  runSample(0x80000000, -1);
  runSample(0x80000000, 0x80000000);

  return 0;
}