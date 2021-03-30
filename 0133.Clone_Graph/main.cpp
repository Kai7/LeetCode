#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

Node* runSample(Node *node){
  std::cout << "Input: node = \n" << toString_Graph(node) << std::endl;
  Solution solver;
  Node *ans = solver.cloneGraph(node);
  std::cout << "Output: \n" << toString_Graph(ans) << std::endl << std::endl;
  return ans;
}

int main(){
  Node *n1 = new Node(10);
  Node *n2 = new Node(20);
  Node *n3 = new Node(30);
  Node *n4 = new Node(40);
  n1->neighbors.push_back(n2);
  n1->neighbors.push_back(n4);
  n2->neighbors.push_back(n1);
  n2->neighbors.push_back(n3);
  n3->neighbors.push_back(n2);
  n3->neighbors.push_back(n4);
  n4->neighbors.push_back(n1);
  n4->neighbors.push_back(n3);

  Node *ans = runSample(n1);

  deleteGraph(n1);
  deleteGraph(ans);

  return 0;
}