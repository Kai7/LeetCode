#include "utils/data_structure.hpp"

#define METHOD 1

class Solution {
public:
#if METHOD == 0
  /* TODO */

#elif METHOD == 2
  /* 19.10, 94.53 */
  Node* cloneGraph(Node* node) {
    if (node == nullptr) return node;
    std::map<Node*, Node*> buffer;
    std::map<int, Node*> created;
    Node* tmp_node = new Node(node->val);
    Node* ans = tmp_node;
    created[tmp_node->val] = tmp_node;
    buffer.insert(std::pair<Node*, Node*>(tmp_node, node));
    while(!buffer.empty()){
      auto it = buffer.begin();
      for (int i = 0; i < it->second->neighbors.size(); ++i) {
        if (created.find(it->second->neighbors[i]->val) != created.end()) {
          it->first->neighbors.push_back(created[it->second->neighbors[i]->val]);
          continue;
        }
        tmp_node = new Node(it->second->neighbors[i]->val);   
        it->first->neighbors.push_back(tmp_node);
        created[tmp_node->val] = tmp_node;
        buffer.insert(std::pair<Node*, Node*>(tmp_node, it->second->neighbors[i]));
      }
      buffer.erase(it);
    }
    return ans;
  }
#elif METHOD == 1
  /* 91.88, 86.00 */
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
#else
#endif
};