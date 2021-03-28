#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

TreeNode* runSample(ListNode* head){
  std::cout << "Input: head = " << toString(head) << std::endl;
  Solution solver;
  TreeNode *root = solver.sortedListToBST(head);
  std::cout << "Output: " << std::endl
            << "  > " << toString_Inorder(root) << std::endl
            << "  > " << toString_Preorder(root) << std::endl << std::endl;
  return root;
}

int main(){
  size_t n = 3;
  vector<int> data = createVector_Default(n);
  ListNode *head = createLinkedList(data);

  TreeNode *root = runSample(head);

  deleteLinkedList(head);
  deleteBinaryTree(root);
  return 0;
}