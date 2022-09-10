#include "utils/data_structure.hpp"
#include <functional>

class Solution {
public:
  /* 20.14, 17.59 */
  bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    std::function<bool(TreeNode*, TreeNode*)> dfs;
    dfs = [&dfs] (TreeNode *r1, TreeNode *r2) -> bool {
      if (r1 == nullptr && r2 == nullptr) return true;
      if (r1 != nullptr && r2 == nullptr) return false;
      if (r1 == nullptr && r2 != nullptr) return false;
      if (r1->val != r2->val) return false;
      if (false == dfs(r1->left, r2->right)) return false;
      if (false == dfs(r1->right, r2->left)) return false;
      return true;
    };
    return dfs(root->left, root->right);
  }
};