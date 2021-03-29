#include "utils/data_structure.hpp"
#include <iostream>

class Solution {
public:
  Node* cloneGraph(Node* node) {
    if (!node) return nullptr;
    map<Node*, Node*> map_old2new;
    queue<Node*> queue_wait;
    queue_wait.push(node);
    while (!queue_wait.empty()){
      Node *target_node = queue_wait.front();
    }
    return nullptr;
  }
};