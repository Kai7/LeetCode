#include "utils/data_structure.hpp"
#include <iostream>

class Solution {
public:
  /* Accepted: 81.49, 97.95 */
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode **buffer_tree_nodes = new TreeNode*[nums.size()];
    for (size_t i = 0; i < nums.size(); i++) buffer_tree_nodes[i] = new TreeNode(nums[i]);
    TreeNode *root = createBST(buffer_tree_nodes, 0, static_cast<int>(nums.size()) - 1);
    delete [] buffer_tree_nodes;
    return root;
  }

private:
  TreeNode* createBST(TreeNode **buffer_TN, int front, int rear){
    if (front > rear) return nullptr;
    int mid = (front + rear) / 2;
    buffer_TN[mid]->left = createBST(buffer_TN, front, mid - 1);
    buffer_TN[mid]->right = createBST(buffer_TN, mid + 1, rear);
    return buffer_TN[mid];
  }
};