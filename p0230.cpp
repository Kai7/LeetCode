#include "utils/data_structure.hpp"


class Solution {
public:
  /* 24.37, 60.35 */
  int counter = 0;
  int ans;
  void helper(TreeNode* root, int k) {
    if (root == nullptr) return;
    if (counter == k) return;
    helper(root->left, k);
    if (counter == k) return;
    counter++;
    if (counter == k) {
      ans = root->val;
      return;
    }
    helper(root->right, k);
    return;
  }
  int kthSmallest(TreeNode* root, int k) {
    helper(root, k);
    return ans;
  }
};