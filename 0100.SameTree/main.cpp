#include "solver.hpp"
#include <iostream>

void runSameTree(TreeNode *p, TreeNode *q){
  Solution solver;
  if (solver.isSameTree(p, q)){
    std::cout << "same tree." << std::endl;
  } else {
    std::cout << "NOT same tree." << std::endl;
  }
}

void freeTree(TreeNode *r){
  if (r == nullptr) return;
  freeTree(r->left);
  freeTree(r->right);
  delete r;
}

int main(int argc, char **argv){
  TreeNode *p = new TreeNode(2);
  p->left = new TreeNode(1);
  p->right = new TreeNode(3);
  TreeNode *q = new TreeNode(2);
  q->left = new TreeNode(1);
  q->right = new TreeNode(3);

  runSameTree(p, q);
  freeTree(p);
  freeTree(q);

  // std::cout << p->val << std::endl;
  return 0;
}