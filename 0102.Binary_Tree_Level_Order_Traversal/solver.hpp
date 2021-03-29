#include "utils/data_structure.hpp"
#include <iostream>

class Solution {
public:
  /* Accepted: 100.00, 81.53 */
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> queue_nodes;
    if (root != nullptr) queue_nodes.push(root);
    while (!queue_nodes.empty()) {
      vector<int> sub_traversal;
      size_t level_size = queue_nodes.size();
      for (size_t i = 0; i < level_size; i++){
        TreeNode* sub_root = queue_nodes.front();
        queue_nodes.pop();
        sub_traversal.push_back(sub_root->val);
        if (sub_root->left != nullptr) queue_nodes.push(sub_root->left);
        if (sub_root->right != nullptr) queue_nodes.push(sub_root->right);
      }
      ans.push_back(std::move(sub_traversal));
    }
    return ans;
  }

#if 0
  /* Accepted: 80.30, 58.92 */
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> queue_nodes;
    if (root != nullptr) queue_nodes.push(root);
    while (!queue_nodes.empty()) {
      vector<int> sub_traversal;
      size_t level_size = queue_nodes.size();
      for (size_t i = 0; i < level_size; i++){
        TreeNode* sub_root = queue_nodes.front();
        queue_nodes.pop();
        sub_traversal.push_back(sub_root->val);
        if (sub_root->left != nullptr) queue_nodes.push(sub_root->left);
        if (sub_root->right != nullptr) queue_nodes.push(sub_root->right);
      }
      ans.push_back(sub_traversal);
    }
    return ans;
  }
#endif
};