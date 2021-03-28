#include "utils/data_structure.hpp"
#include "utils/utils.hpp"
#include <iostream>
#include "stdio.h"

int main(){
  vector<int> data = createVector_Default(2000);
  // vector<int> data = createVector_Random(2000);
  // std::cout << "data: " << toString(data) << std::endl;

  clock_t tStart = clock();
  TreeNode *root = createAVLTree(data);
  printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  // std::cout << "preorder: " << toString_Preorder(root) << std::endl;

  deleteBinaryTree(root);

  return 0;

}