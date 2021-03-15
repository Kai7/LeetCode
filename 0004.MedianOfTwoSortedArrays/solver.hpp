#include <vector>
using std::vector;
#include <iostream>

#define MIN(a,b) (((a)<(b))?(a):(b))

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    size_t total = nums1.size() + nums2.size();
    size_t idx_m = (total + 1) / 2;
    size_t idx_1 = 0, idx_2 = 0;
    size_t counter = 0;
    double median;
    while(idx_1 < nums1.size() && idx_2 < nums2.size()){
      if (nums1[idx_1] <= nums2[idx_2]){
        idx_1++;
        if (counter + 1 == idx_m){
          median = static_cast<double>(nums1[idx_1-1]);
          counter++;
          break;
        }
      }else{
        idx_2++;
        if (counter + 1 == idx_m){
          median = static_cast<double>(nums2[idx_2-1]);
          counter++;
          break;
        }
      }
      counter++;
    }
    if (counter != idx_m){
      if (idx_1 < nums1.size()){
        idx_1 += idx_m - counter;
        median = static_cast<double>(nums1[idx_1-1]);
        if (total % 2 == 1) return median;
        return (median + static_cast<double>(nums1[idx_1])) / 2. ;
      } else{
        idx_2 += idx_m - counter;
        median = static_cast<double>(nums2[idx_2-1]);
        if (total % 2 == 1) return median;
        return (median + static_cast<double>(nums2[idx_2])) / 2. ;
      }
    } else {
      if (total % 2 == 1) return median;
      if (idx_1 == nums1.size()) return (median + static_cast<double>(nums2[idx_2])) / 2. ;
      if (idx_2 == nums2.size()) return (median + static_cast<double>(nums1[idx_1])) / 2. ;
      return (median + static_cast<double>(MIN(nums1[idx_1], nums2[idx_2]))) / 2. ;
    }
  }
};