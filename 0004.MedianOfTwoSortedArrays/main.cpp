#include "solver.hpp"
#include "utils/utils.hpp"

void runMedianOfTwoSortedArrays(vector<int>& nums1, vector<int>& nums2){
  Solution solver;
  double m = solver.findMedianSortedArrays(nums1, nums2);
  std::cout << "input:" << std::endl
            << "\tnums1: " << vector2str(nums1) << std::endl
            << "\tnums2: " << vector2str(nums2) << std::endl
            << "output:" << std::endl
            << "\tmedian = " << m << std::endl;
  return;
}

int main(int argc, char **argv){
  vector<int> nums1 = {0, 1, 4, 9, 15, 19, 20};
  // vector<int> nums1 = {0, 1, 4};
  // vector<int> nums2 = {2, 3};
  vector<int> nums2 = {1, 2, 3};
  runMedianOfTwoSortedArrays(nums1, nums2);

  return 0;
}