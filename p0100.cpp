#include "utils/data_structure.hpp"

class Solution {
public:
  /* 26.98, 94.98 */
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q != nullptr) return false;
    if (p != nullptr && q == nullptr) return false;
    if (p == nullptr && q == nullptr) return true;
    if (p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};