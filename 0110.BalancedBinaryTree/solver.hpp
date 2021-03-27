#include "utils/data_structure.hpp"
#include <iostream>

#define MAX(a,b) (((a)>(b))?(a):(b))

class Solution {
public:
  /* Accepted: 6.39, 16.35 */
  bool isBalanced(TreeNode* root) {
    if (root == nullptr) return true;
    if (!isBalanced(root->left) || !isBalanced(root->right)) return false;
    int balance_factor = getBalanceFactor(root);
    if (balance_factor < -1 || balance_factor > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
  }

private:
  int getBalanceFactor(TreeNode* root) {
    return getHeight(root->left) - getHeight(root->right);
  }

  int getHeight(TreeNode* root) {
    if (root == nullptr) return -1;
    return 1 + MAX(getHeight(root->left), getHeight(root->right));
  }
};