struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#define METHOD 0

class Solution {
public:
#if METHOD == 0
  /* Accepted: 81.17, 38.74 */
  TreeNode* prev = nullptr;
  void flatten(TreeNode* root) {
    if(root==nullptr) return;
    flatten(root->right);
    flatten(root->left);
    root->right = prev;
    root->left = nullptr;
    prev = root;
  }
#elif METHOD == 1
  /* Accepted: 29.44, 38.74 */
  TreeNode* doFlatten(TreeNode* root) {
    if (root == nullptr) return nullptr;
    TreeNode *l_rear =  doFlatten(root->left);
    TreeNode *r_rear =  doFlatten(root->right);
    TreeNode *rear_node = (r_rear != nullptr) ? r_rear : (l_rear != nullptr) ? l_rear : root;
    if (root->left != nullptr) {
      l_rear->right = root->right;
      root->right = root->left;
      root->left = nullptr;
    }
    return rear_node;
  }

  void flatten(TreeNode* root) {
    doFlatten(root);
  }
#else
#error ""
#endif
};