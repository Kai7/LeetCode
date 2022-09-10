#include "utils/data_structure.hpp"

#define METHOD 0

class Solution {
public:
#if METHOD == 0
  /* 100.00, 39.94 */
  vector<int> inorderTraversal(TreeNode* root) {
    /* Morris Traversal */
    vector<int> ans;
    TreeNode *p = root;
    while (p != nullptr) {
      if (p->left == nullptr) {
        ans.push_back(p->val);
        p = p->right;
        continue;
      }
      TreeNode *q = p->left;
      while (q->right != nullptr && q->right != p) q = q->right;
      if (q->right == p) {
        q->right = nullptr;
        ans.push_back(p->val);
        p = p->right;
      } else {
        q->right = p;
        p = p->left;
      }
    }
    return ans;
  }

#elif METHOD == 2
  /* 41.51, 39.94 */
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> stk;
    TreeNode *p = root;
    while (p || !stk.empty()) {
      while (p != nullptr) {
        stk.push(p);
        p = p->left;
      }
      p = stk.top();
      stk.pop();
      ans.push_back(p->val);
      p = p->right;
    }
    return ans;
  }

#elif METHOD == 1
  /* 100.00, 98.01 */
  void helper(TreeNode* root, vector<int>& trace) {
    if (root == nullptr) return;
    if (root->left != nullptr) helper(root->left, trace);
    trace.push_back(root->val);
    if (root->right != nullptr) helper(root->right, trace);
    return;
  }

  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    helper(root, ans);
    return ans;
  }
#else
#endif
};