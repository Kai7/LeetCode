#include "solver.hpp"
#include "utils/utils.hpp"


void runMaximumSubarray(vector<int> &nums){
  Solution solver;
  std::cout << "input:  " << toString(nums) << std::endl;
  std::cout << "output: " << solver.maxSubArray(nums) << std::endl;
}

int main(int argc, char **argv){
  vector<int> test = {-2,1,-3,4,-1,2,1,-5,4};
  runMaximumSubarray(test);
  return 0;
}