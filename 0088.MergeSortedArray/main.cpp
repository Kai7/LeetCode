#include "solver.hpp"
#include "utils/utils.hpp"

void runMergeSortedArray(vector<int>& nums1, int m, vector<int>& nums2, int n){
  Solution solver;
  std::cout << "input:\n"
            << "\tnums1: " << toString(nums1) << std::endl
            << "\tnums2: " << toString(nums2) << std::endl;
  solver.merge(nums1, m, nums2, n);
  std::cout << "output: " << toString(nums1) << std::endl;
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