#include "utils/data_structure.hpp"
#include <iostream>

class Solution {
public:
  /* Accepted: 95.11, 86.69 */
  Node* cloneGraph(Node* node) {
    if (!node) return nullptr;
    map<Node*, Node*> map_old2new;
    queue<Node*> queue_wait;
    map_old2new[node] = new Node(node->val);
    queue_wait.push(node);
    while (!queue_wait.empty()){
      Node *target_node = queue_wait.front();
      queue_wait.pop();
      vector<Node*> &t_neighbors = target_node->neighbors;
      for (size_t i = 0; i < t_neighbors.size(); i++){
        if (map_old2new.find(t_neighbors[i]) == map_old2new.end()){            
          map_old2new[t_neighbors[i]] = new Node(t_neighbors[i]->val);
          queue_wait.push(t_neighbors[i]);
        }
        map_old2new[target_node]->neighbors.push_back(map_old2new[t_neighbors[i]]);
      }
    }
    return map_old2new[node];
  }
};