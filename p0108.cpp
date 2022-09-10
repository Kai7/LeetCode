#include "utils/data_structure.hpp"

class Solution {
public:
  /* 65.25, 77.25 */
  TreeNode* helper(vector<int>& nums, int start, int end) {
    if (start > end) return nullptr;
    int middle = (start + end) / 2;
    TreeNode* root = new TreeNode(nums[middle]);
    root->left  = helper(nums, start, middle - 1);
    root->right = helper(nums, middle + 1, end);
    return root;
  }
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
  }
};