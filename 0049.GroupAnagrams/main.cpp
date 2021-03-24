#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(vector<string>& strs){
  std::cout << "Input: strs = " << toString(strs) << std::endl;
  Solution solver;
  vector<vector<string>> ans = solver.groupAnagrams(strs);
  std::cout << "Output: " << toString(ans) << std::endl << std::endl;
}

int main(){
  // vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
  // vector<string> strs = {""};
  vector<string> strs = {"a"};

  runSample(strs);

  return 0;
}