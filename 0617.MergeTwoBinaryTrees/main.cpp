#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

TreeNode* runSample(TreeNode* root1, TreeNode* root2){
  std::cout << "Input:" << std::endl
            << "  root1 = " << toString_Preorder(root1) << std::endl
            << "  root2 = " << toString_Preorder(root2) << std::endl;
  Solution solver;
  TreeNode *ans = solver.mergeTrees(root1, root2);
  std::cout << "Output: " << toString_Preorder(ans) << std::endl << std::endl;
  return ans;
}

int main(){
  vector<int> data1 = createVector_Random(8);
  vector<int> data2 = createVector_Random(8);

  std::cout << "data1 = " << toString(data1) << std::endl;
  std::cout << "data2 = " << toString(data2) << std::endl;

  TreeNode* root1 = createBinaryTree(data1);
  TreeNode* root2 = createBinaryTree(data2);

  root1 = runSample(root1, root2);

  deleteBinaryTree(root1);
  return 0;
}