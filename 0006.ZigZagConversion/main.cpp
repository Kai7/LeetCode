#include "solver.hpp"

void runSample(string s, int numRows){
  Solution solver;
  string ans = solver.convert(s, numRows);
  std::cout << "input  : s = \"" << s << "\", numRow = " << numRows << std::endl;
  std::cout << "output : \"" << ans << "\"" << std::endl;
  std::cout << std::endl;
}

int main(int argc, char **argv){
  runSample("PAYPALISHIRING", 3);
  runSample("A", 1);
  runSample("ABCD", 2);
  return 0;
}