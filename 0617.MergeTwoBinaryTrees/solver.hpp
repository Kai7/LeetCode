#include "utils/data_structure.hpp"
#include <iostream>

class Solution {
public:
  /* Accepted: 64.56, 60.37 */
  TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr) return root2;
    if (root2 == nullptr) return root1;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    root1->val += root2->val;
    delete root2;
    return root1;
  }
};