#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(TreeNode* root) {
  std::cout << "Input: root = " << toString_Preorder(root) << std::endl;
  Solution solver;
  int ans = solver.sumNumbers(root);
  std::cout << "Output: " << ans << std::endl << std::endl;
}

int main(){
  // vector<int> data = {2,1,3};
  vector<int> data = {3,1,5,2,4,7};
  std::cout << "data = " << toString(data) << std::endl;

  TreeNode *root = createBinaryTree(data);

  runSample(root);

  deleteBinaryTree(root);
  return 0;
}
