#include "utils/data_structure.hpp"

#include <iostream>
using std::cout;
using std::endl;

#define METHOD 0

class Solution {
public:
#if METHOD == 0
  /* 92.62, 70.37 */
  bool isValidBST(TreeNode *root) {
    if (!root) return true;
    TreeNode *cur = root, *pre, *parent = NULL;
    bool res = true;
    while (cur) {
      if (!cur->left) {
        if (parent && parent->val >= cur->val) res = false;
        parent = cur;
        cur = cur->right;
      } else {
        pre = cur->left;
        while (pre->right && pre->right != cur) pre = pre->right;
        if (!pre->right) {
          pre->right = cur;
          cur = cur->left;
        } else {
          pre->right = NULL;
          if (parent->val >= cur->val) res = false;
          parent = cur;
          cur = cur->right;
        }
      }
    }
    return res;
  }

  /* ERROR */
  bool isValidBST(TreeNode *root) {
    if (!root) return true;
    TreeNode *cur = root, *pre, *parent = NULL;
    while (cur) {
      if (!cur->left) {
        if (parent && parent->val >= cur->val) return false;
        parent = cur;
        cur = cur->right;
      } else {
        pre = cur->left;
        while (pre->right && pre->right != cur) pre = pre->right;
        if (!pre->right) {
          pre->right = cur;
          cur = cur->left;
        } else {
          pre->right = NULL;
          if (parent->val >= cur->val) return false;
          parent = cur;
          cur = cur->right;
        }
      }
    }
    return true;
  }

  /* FIXED */
  bool isValidBST(TreeNode* root) {
    TreeNode *p = root;
    TreeNode *t = nullptr;
    bool ans = true;
    while (p != nullptr) {
      if (p->left == nullptr) {
        if (t != nullptr && t->val >= p->val) ans = false;
        t = p;
        p = p->right;
        continue;
      }
      TreeNode *q = p->left;
      while (q->right != nullptr && q->right != p) q = q->right;
      if (q->right == p) {
        if (t->val >= p->val) ans = false;
        q->right = nullptr;
        t = p;
        p = p->right;
      } else {
        q->right = p;
        p = p->left;
      }
    }
    return true;
  }

#elif METHOD == 1
  /* 7.20, 88.87 */
  bool init = false;
  int pre = INT32_MIN;
  bool isValidBST(TreeNode* root) {
    if (root == nullptr) return true;
    if (!isValidBST(root->left)) return false;  
    if (init) {
      if (root->val <= pre) return false;
    } else {
      init = true;
    }
    pre = root->val;
    return isValidBST(root->right);
  }
#else
#endif
};