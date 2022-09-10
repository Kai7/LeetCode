#include "utils/data_structure.hpp"

class Solution {
public:
  /* 38.56, 77.11 */
  TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int pre_start, int in_start, int size) {
    if (size <= 0) return nullptr;
    TreeNode *node = new TreeNode(preorder[pre_start]);
    int idx = -1;
    for (int i = in_start; i < in_start + size; i++) {
      if (inorder[i] == node->val) {
        idx = i;
        break;
      }
    }
    int left_size = idx - in_start;
    int right_size = size - left_size - 1;
    node->left = helper(preorder, inorder, pre_start + 1, in_start, left_size);
    node->right = helper(preorder, inorder, pre_start + 1 + left_size, in_start + 1 + left_size, right_size);
    return node;
  }
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return helper(preorder, inorder, 0, 0, preorder.size());
  }
};