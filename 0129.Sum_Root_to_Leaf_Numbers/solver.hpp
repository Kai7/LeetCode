#include "utils/data_structure.hpp"
#include <iostream>

class Solution {
public:
  /* Accepted: 53.25, 59.05 */
  int sumNumbers(TreeNode* root) {
    if (!root) return 0;
    int ans = 0;
    traversalSum(root, 0, ans);
    return ans;
  }

private:
  void traversalSum(TreeNode *root, int current_num, int &sum){
    current_num = current_num * 10 + root->val;
    if (!root->left && !root->right){
      sum += current_num;
      return;
    }
    if (root->left) {
      traversalSum(root->left, current_num, sum);
    }
    if (root->right) {
      traversalSum(root->right, current_num, sum);
    }
  }
};