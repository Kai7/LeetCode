#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(TreeNode* root){
  // std::cout << "Input: root = " << toString_Preorder(root) << std::endl;
  Solution solver;
  clock_t tStart = clock();
  vector<vector<int>> ans = solver.zigzagLevelOrder(root);
  printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  // std::cout << "Output: " << toString(ans) << std::endl << std::endl;
}

int main(){
  // vector<int> data = {5,2,7,6,9};
  size_t n = 1000;
  vector<int> data = createVector_Default(n);
  // vector<int> data = createVector_Random(n);
  // std::cout << "data = " << toString(data) << std::endl;

  // TreeNode* root = createBinaryTree(data);
  TreeNode* root = createAVLTree(data);

  runSample(root);

  deleteBinaryTree(root);
  return 0;
}