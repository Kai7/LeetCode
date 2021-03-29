#include "utils/data_structure.hpp"
#include <iostream>

#include <algorithm>

class Solution {
public:
#if 1
  /* Accepted: 63.32, 74.54 */
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (root == nullptr) return {};
    vector<vector<int>> ans;
    stack<TreeNode*> stack_nodes[2];
    stack_nodes[0].push(root);
    for (int i = 0; !stack_nodes[i%2].empty(); i++){
      auto &cur_stack = stack_nodes[i%2];
      auto &nxt_stack = stack_nodes[(i+1)%2];
      vector<int> tmp_traversal;
      tmp_traversal.reserve(cur_stack.size());
      while(!cur_stack.empty()){
        TreeNode *tmp_node = cur_stack.top();
        cur_stack.pop();
        tmp_traversal.push_back(tmp_node->val);
        if (i%2 == 0){
          if (tmp_node->left != nullptr) nxt_stack.push(tmp_node->left);
          if (tmp_node->right != nullptr) nxt_stack.push(tmp_node->right);
        } else {
          if (tmp_node->right != nullptr) nxt_stack.push(tmp_node->right);
          if (tmp_node->left != nullptr) nxt_stack.push(tmp_node->left);
        }
      }
      ans.push_back(std::move(tmp_traversal));
    }
    return ans;
  }
#endif

#if 0
  /* Accepted: 63.32, 98.69 */
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> queue_nodes;
    bool reverse = false;
    if (root) queue_nodes.push(root);
    while (!queue_nodes.empty()) {
      vector<int> sub_traversal;
      size_t level_size = queue_nodes.size();
      for (size_t i = 0; i < level_size; i++){
        TreeNode* sub_root = queue_nodes.front();
        queue_nodes.pop();
        sub_traversal.push_back(sub_root->val);
        if (sub_root->left) queue_nodes.push(sub_root->left);
        if (sub_root->right) queue_nodes.push(sub_root->right);
      }
      if (reverse) std::reverse(sub_traversal.begin(), sub_traversal.end());
      reverse = !reverse;
      ans.push_back(std::move(sub_traversal));
    }
    return ans;
  }
#endif

#if 0
  /* Accepted: 63.32, 21.89 */
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    stack<TreeNode*> stack_nodes;
    bool reverse = false;
    if (root != nullptr) stack_nodes.push(root);
    while (!stack_nodes.empty()){
      vector<int> sub_ans;
      stack<TreeNode*> tmp_stack_nodes;
      while(!stack_nodes.empty()){
        TreeNode *sub_root = stack_nodes.top();
        stack_nodes.pop();
        sub_ans.push_back(sub_root->val);
        if(!reverse) {
          if (sub_root->left != nullptr) tmp_stack_nodes.push(sub_root->left);
          if (sub_root->right != nullptr) tmp_stack_nodes.push(sub_root->right);
        } else {
          if (sub_root->right != nullptr) tmp_stack_nodes.push(sub_root->right);
          if (sub_root->left != nullptr) tmp_stack_nodes.push(sub_root->left);
        }
      }
      reverse = !reverse;
      ans.push_back(std::move(sub_ans));
      stack_nodes = std::move(tmp_stack_nodes);
    }
    return ans;
  }
#endif
};