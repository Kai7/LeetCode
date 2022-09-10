#include "utils/data_structure.hpp"

class Solution {
public:
  /* 95.08, 68.42 */
  int max_value;    
  int helper(TreeNode* root) {
    if (root == nullptr) return 0;
    int l_max = std::max(helper(root->left), 0);
    int r_max = std::max(helper(root->right), 0);
    max_value = std::max(max_value, root->val + l_max + r_max);
    return root->val + std::max(l_max, r_max);
  }
  int maxPathSum(TreeNode* root) {
    max_value = INT32_MIN;
    helper(root);
    return max_value;
  }
};