#include "solver.hpp"

#include <string>
#include <iterator>
#include <sstream>

std::string vector2str(vector<int> &nums){
  std::stringstream sstr;
  std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(sstr, ", "));
  return sstr.str();
}

void runMaximumSubarray(vector<int> &nums){
  Solution solver;
  std::cout << "input:  " << vector2str(nums) << std::endl;
  std::cout << "output: " << solver.maxSubArray(nums) << std::endl;
}

int main(int argc, char **argv){
  vector<int> test = {-2,1,-3,4,-1,2,1,-5,4};
  runMaximumSubarray(test);
  return 0;
}