#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(int x, int y){
  std::cout << "Input: x = " << x << ", y = " << y << std::endl;
  Solution solver;
  int ans = solver.hammingDistance(x, y);
  std::cout << "Output: " << ans << std::endl << std::endl;
}

int main(){
  runSample(1, 4);
  runSample(7, 32);
  runSample(105, 165);
  runSample(0x80000000, 0x70000000);

  return 0;
}