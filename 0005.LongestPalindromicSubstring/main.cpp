#include "solver.hpp"

void runSample(string s){
  Solution solver;
  string ans = solver.longestPalindrome(s);
  std::cout << "input: " << std::endl
            << "  1. " << s << std::endl
            << "output:" << std::endl
            << "     " << ans << std::endl << std::endl;
  return;
}

int main(int argc, char **argv) {
  runSample("a");
  runSample("ab");
  runSample("abac");
  return 0;
}