#include "utils/data_structure.hpp"
#include <iostream>

#define MAX(a,b) (((a)>(b))?(a):(b))

class Solution {
public:
  /* Accepted: 88.52, 15.40 */
  bool isBalanced(TreeNode* root) {
    return checkBalance(root).first;
  }

  pair<bool,int> checkBalance(TreeNode *root){
    if (root == nullptr) return {true, -1};
    pair<bool, int> result_left = checkBalance(root->left);
    if (!result_left.first) return {false, -1};
    pair<bool, int> result_right = checkBalance(root->right);
    if (!result_right.first) return {false, -1};
    if (abs(result_left.second - result_right.second) > 1) return {false, -1};
    return {true, 1 + MAX(result_left.second, result_right.second)};
  }


#if 0
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
#endif
};