#include "solver.hpp"

void runReverseInteger(int x){
  Solution solver;
  int rev_x = solver.reverse(x);
  std::cout << "input: " << x << ", output: " << rev_x << std::endl;
}

int main(int argc, char **argv){
  runReverseInteger(123);
  runReverseInteger(-482740);
  runReverseInteger(1463847412);
  runReverseInteger(1563847412);
  runReverseInteger(-2147483648);
  runReverseInteger(-2147483412);
  return 0;
}