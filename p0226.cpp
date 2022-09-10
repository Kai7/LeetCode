#include "utils/data_structure.hpp"

class Solution {
public:
  /* 70.96, 38.50 */
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return root;
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
  }
};