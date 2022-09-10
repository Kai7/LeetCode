#include "utils/data_structure.hpp"

class Solution {
public:
  /* 40.33, 21.29 */
  bool isSameTree(TreeNode* root_1, TreeNode* root_2) {
    if (root_1 == nullptr && root_2 != nullptr) return false;
    if (root_1 != nullptr && root_2 == nullptr) return false;
    if (root_1 == nullptr && root_2 == nullptr) return true;
    if (root_1->val != root_2->val) return false;
    return isSameTree(root_1->left, root_2->left) && isSameTree(root_1->right, root_2->right);
  }

  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (subRoot == nullptr) return true;
    if (root == nullptr) return false;
    if (root->val == subRoot->val) {
      if (isSameTree(root, subRoot)) return true;
    }
    if (isSubtree(root->left, subRoot)) return true;
    if (isSubtree(root->right, subRoot)) return true;
    return false;
  }
};