#include "solver.hpp"
#include "utils/utils.hpp"

void runSearchInsertPosition(vector<int> &nums, int target){
  Solution solver;
  std::cout << "input:\n"
            << "\tnums: " << toString(nums) << std::endl
            << "\ttarget: " << target << std::endl
            << "output: " << solver.searchInsert(nums, target) << std::endl;
}

int main(int argc, char **argv){
  vector<int> nums = {1, 3, 5, 6};
  int target = 5;
  runSearchInsertPosition(nums, target);
  
  return 0;
}