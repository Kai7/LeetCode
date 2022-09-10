#include "utils/data_structure.hpp"

class Solution {
public:
  /* 37.58, 63.86 */
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) return nullptr;
    if (root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
    if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
    return root;
  }
};