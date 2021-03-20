#include "solver.hpp"
#include "utils/utils.hpp"

void runSample(vector<string>& strs){
  Solution solver;
  string ans = solver.longestCommonPrefix(strs);
  std::cout << "Input: strs = " << toString(strs) << std::endl;
  std::cout << "Output: \"" << ans << "\"" << std::endl << std::endl;
}

int main(){
  vector<string> test_1 = {"flower","flow","flight"};
  vector<string> test_2 = {"flower","flow","flight",""};

  runSample(test_1);
  runSample(test_2);

  return 0;
}