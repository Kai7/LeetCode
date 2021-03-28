#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(TreeNode* root){
  std::cout << "Intput: root = " << toString_Preorder(root) << std::endl;
  Solution solver;
  bool ans = solver.isBalanced(root);
  std::cout << "Output: " << toString(ans) << std::endl << std::endl;
  return;
}

int main(){
  // vector<int> data = createVector_Default(10);
  vector<int> data = createVector_Random(10);
  std::cout << "data: " << toString(data) << std::endl;

  // TreeNode *root = createBinaryTree(data);
  TreeNode *root = createAVLTree(data);

  runSample(root);

  deleteBinaryTree(root);
  return 0;
}