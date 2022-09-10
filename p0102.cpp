#include "utils/data_structure.hpp"

class Solution {
public:
  /* 88.67, 85.19 */
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == nullptr) return ans;
    queue<pair<TreeNode*, int>> q;
    q.push(pair<TreeNode*, int>(root, 0));
    while(!q.empty()) {
      auto p = q.front();
      q.pop();
      if (p.second >= ans.size()) {
        ans.push_back(vector<int>({}));
      }
      ans[p.second].push_back(p.first->val);
      if (p.first->left  != nullptr) q.push(pair<TreeNode*, int>(p.first->left, p.second + 1));
      if (p.first->right != nullptr) q.push(pair<TreeNode*, int>(p.first->right, p.second + 1));
    }
    return ans;
  }
};