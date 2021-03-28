#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

TreeNode* runSample(vector<int> &nums){
  std::cout << "Input: head = " << toString(nums) << std::endl;
  Solution solver;
  TreeNode *root = solver.sortedArrayToBST(nums);
  std::cout << "Output: " << std::endl
            << "  > " << toString_Inorder(root) << std::endl
            << "  > " << toString_Preorder(root) << std::endl << std::endl;
  return root;
}

int main(){
  size_t n = 10;
  vector<int> nums = createVector_Default(n);

  TreeNode *root = runSample(nums);

  deleteBinaryTree(root);
  return 0;
}