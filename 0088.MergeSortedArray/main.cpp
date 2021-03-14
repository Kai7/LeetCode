#include "solver.hpp"

#include <string>
#include <iterator>
#include <sstream>

std::string vector2str(vector<int> &nums){
  std::stringstream sstr;
  std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(sstr, ", "));
  return sstr.str();
}

void runMergeSortedArray(vector<int>& nums1, int m, vector<int>& nums2, int n){
  Solution solver;
  std::cout << "input:\n"
            << "\tnums1: " << vector2str(nums1) << std::endl
            << "\tnums2: " << vector2str(nums2) << std::endl;
  solver.merge(nums1, m, nums2, n);
  std::cout << "output: " << vector2str(nums1) << std::endl;
  return;
}

int main(int argc, char **argv){
  // vector<int> nums1 = {1,2,3,0,0,0};
  // vector<int> nums2 = {2,5,6};
  // vector<int> nums1 = {1,2,7,9, 0,0,0};
  // vector<int> nums2 = {3,5,6};
  vector<int> nums1 = {0};
  vector<int> nums2 = {1};
  runMergeSortedArray(nums1, nums1.size() - nums2.size(), nums2, nums2.size());

  return 0;
}