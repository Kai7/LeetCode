#include "utils/data_structure.hpp"
#define METHOD 0
class Solution {
public:
#if METHOD == 0
  int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (target == nums[mid]) {
        return mid;
      }
      
      if (nums[mid] >= nums[left]) {
        if (target >= nums[left] && target < nums[mid]) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
      }
      
      else {
        if (target <= nums[right] && target > nums[mid]) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
      }
      
    }
    return -1;
  }

#elif METHOD == 2
    int search(vector<int>& nums, int target) {
      int l = 0;
      int r = nums.size() - 1;
      while (l <= r) {
        int middle = (l + r) / 2;
        if (nums[middle] == target) return middle;
        if (nums[l] > nums[r]) {
          if (nums[middle] > nums[r]) {
            if(target < nums[middle] && target > nums[r]) {
              r = middle - 1;          
            } else {
              l = middle + 1;
            } 
          } else {
            if (target > nums[middle] && target < nums[l]) {
              l = middle + 1;
            } else {
              r = middle - 1;          
            }
          }
        } else {
          if (target > nums[middle]) {
            l = middle + 1;
          } else {
            r = middle - 1;
          }
        }
      }
      return -1;
    }
#elif METHOD == 1
    int findPivotIndex(vector<int>& nums, int l, int r) {
      if (l == r) return l;
      int middle = (l + r) / 2;
      if (nums[middle] > nums[r]) {
          return findPivotIndex(nums, middle + 1, r);
      } else {
          return findPivotIndex(nums, l, middle);
      }
    }
    int findTargetIndex(vector<int>& nums, int target, int l, int r) {
      if (l > r) return -1;
      if (l == r) {
          if (nums[l] != target) return -1;
          return l;
      }
      int middle = (l + r) / 2;
      if (nums[middle] == target) return middle;
      if (nums[middle] > target) {
          return findTargetIndex(nums, target, l, middle - 1);
      } else {
          return findTargetIndex(nums, target, middle + 1, r);
      }
    }
    int search(vector<int>& nums, int target) {
      int pivot_idx = findPivotIndex(nums, 0, nums.size() - 1);
      if (pivot_idx == 0) return findTargetIndex(nums, target, 0, nums.size() - 1);
      if (target >= nums[0]) return findTargetIndex(nums, target, 0, pivot_idx - 1);
      return findTargetIndex(nums, target, pivot_idx, nums.size() - 1);
    }
#else
#endif
};