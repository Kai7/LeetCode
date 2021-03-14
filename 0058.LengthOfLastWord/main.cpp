#include "solver.hpp"

void runLengthOfLastWord(string s){
  Solution solver;
  std::cout << "input: \"" << s  << "\"" << std::endl
            << "output: " << solver.lengthOfLastWord(s) << std::endl << std::endl;
  return;
}

int main(int argc, char **argv){
  runLengthOfLastWord(string("Hello World"));
  runLengthOfLastWord(string("  "));
  runLengthOfLastWord(string("aabbc  "));
  runLengthOfLastWord(string(" "));
  runLengthOfLastWord(string(""));
  return 0;
}