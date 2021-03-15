#include "solver.hpp"

void runSample(string s){
  Solution solver;
  int max_length = solver.lengthOfLongestSubstring(s);
  std::cout << "input: " << s << std::endl
            << "output: " << max_length << std::endl;
  return;
}

int main(int argc, char **argv){
  runSample("a");
  runSample("aaa");
  runSample("aaabc");
  runSample("pwwkew");
  runSample("abcedgasec");
  return 0;
}