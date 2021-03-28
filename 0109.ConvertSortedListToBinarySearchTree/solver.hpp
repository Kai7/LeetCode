#include "utils/data_structure.hpp"
#include <iostream>

class Solution {
public:
  /* Accepted: 91.71, 98.84 */
  TreeNode* sortedListToBST(ListNode* head) {
    if (head == nullptr) return nullptr;
    int counter = 0;
    ListNode *p = head;
    while (p != nullptr) {
      counter += 1;
      p = p->next;
    }
    TreeNode **buffer_tree_nodes = new TreeNode*[counter];
    p = head;
    for (int i = 0; i < counter; i++){
      buffer_tree_nodes[i] = new TreeNode(p->val);
      p = p->next;
    }
    TreeNode *root = createBST(buffer_tree_nodes, 0, counter - 1);
    delete [] buffer_tree_nodes;
    return root;
  }

private:
  TreeNode* createBST(TreeNode **buffer_TN, int front, int rear){
    if (front > rear) return nullptr;
    int mid = (front + rear) / 2;
    TreeNode *root = buffer_TN[mid];
    root->left = createBST(buffer_TN, front, mid - 1);
    root->right = createBST(buffer_TN, mid + 1, rear);
    return root;
  }
  
};