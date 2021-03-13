#include "solver.hpp"

void runRomanToInteger(string str){
  Solution solver;
  int ans = solver.romanToInt(str);
  std::cout << str << " = " << ans << std::endl;
}

int main(int argc, char **argv){
  runRomanToInteger("I");
  runRomanToInteger("V");
  runRomanToInteger("VI");
  runRomanToInteger("IV");
  runRomanToInteger("MCMXCIV");
}