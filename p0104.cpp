#include "utils/data_structure.hpp"

class Solution {
public:
  /* 94.30, 89.83 */
  int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
  }
};