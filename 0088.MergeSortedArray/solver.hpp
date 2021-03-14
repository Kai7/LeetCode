#include <vector>
using std::vector;
#include <iostream>

class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int idx = m + n - 1;
    m--; n--;
    while (n >= 0 && m >= 0){
      if (nums1[m] > nums2[n]){
        nums1[idx] = nums1[m];
        m--;
      } else {
        nums1[idx] = nums2[n];
        n--;
      }
      idx--;
    }
    while (n >= 0) {
      nums1[idx--] = nums2[n--];
    }
  }

#if 0
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> ans;
    int idx_1 = 0, idx_2 = 0;
    while (idx_1 != m && idx_2 != n) {
      if (nums1[idx_1] <= nums2[idx_2]){
        ans.push_back(nums1[idx_1]);
        idx_1++;
      }else{
        ans.push_back(nums2[idx_2]);
        idx_2++;
      }
    }
    while (idx_1 != m){
      ans.push_back(nums1[idx_1]);
      idx_1++;
    }
    while (idx_2 != n){
      ans.push_back(nums2[idx_2]);
      idx_2++;
    }
    nums1 = ans;     
  }
#endif
};