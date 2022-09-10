#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(vector<int>& candidates, int target) {
  std::cout << "Input: candidates = " << toString(candidates) << ", target = " << target << std::endl;
  Solution solver;
  vector<vector<int>> ans = solver.combinationSum(candidates, target);
  std::cout << "Output: " << toString(ans) << std::endl << std::endl;
}

int main(){
  vector<int> candidates = {2,3,6,7};
  // vector<int> candidates = {2,3,5};
  // vector<int> candidates = {2};

  runSample(candidates, 1);
  runSample(candidates, 2);
  runSample(candidates, 7);
  runSample(candidates, 8);

  return 0;
}