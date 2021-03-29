#ifndef __LEETCODE_UTILS__
#define __LEETCODE_UTILS__

#include <iterator>
#include <sstream>
#include <algorithm>
#include <random>
#include <time.h>

#include "data_structure.hpp"

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

int getHeight(TreeNode *root);
TreeNode* createBinaryTree(vector<int> &nums);
void insertBinaryTree(TreeNode *root, int element);
void insertBinaryTree(TreeNode **root, int element);
void deleteLinkedList(ListNode *head);

TreeNode* createAVLTree(ListNode* head);
pair<TreeNode*, bool> insertAVLTree(TreeNode *root, int element);
TreeNode* balanceAVLTree(TreeNode *root);
TreeNode* rotation_LL(TreeNode *root);
TreeNode* rotation_LR(TreeNode *root);
TreeNode* rotation_RL(TreeNode *root);
TreeNode* rotation_RR(TreeNode *root);
#if 0
TreeNode* insertAVLTree(TreeNode *root, int target);
#endif

string addQuotationMark(string str){
  return "\"" + str + "\"";
}

string toString(bool b){
  return (b)?"true":"false";
}

string toString(vector<int> &nums){
  if (nums.empty()) return "[]";
  std::stringstream sstr;
  sstr << "[" << nums[0];
  for (size_t i = 1; i < nums.size(); i++)
    sstr << "," << nums[i];
  sstr << "]";
  // std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(sstr, ", "));
  return sstr.str();
}

string toString(vector<string> &strs){
  if (strs.empty()) return "[]";
  std::stringstream sstr;
  sstr << "[" << addQuotationMark(strs[0]);
  for (size_t i = 1; i < strs.size(); i++)
    sstr << "," << addQuotationMark(strs[i]);
  sstr << "]";
  // std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(sstr, ", "));
  return sstr.str();
}

string toString(set<string> &strs){
  if (strs.empty()) return "{}";
  std::stringstream sstr;
  set<string>::iterator it = strs.begin();
  sstr << "{" << addQuotationMark(*it);
  it++;
  while (it != strs.end()) {
    sstr << "," << addQuotationMark(*it);
    it++;
  }
  sstr << "]";
  // std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(sstr, ", "));
  return sstr.str();
}

string toString(vector<vector<int>> &nums){
  if (nums.empty()) return "[]";
  std::stringstream sstr;
  sstr << "[" << toString(nums[0]);
  for (size_t i = 1; i < nums.size(); i++)
    sstr << "," << toString(nums[i]);
  sstr << "]";
  return sstr.str();
}

string toString(vector<vector<string>> &strs){
  if (strs.empty()) return "[]";
  std::stringstream sstr;
  sstr << "[" << toString(strs[0]);
  for (size_t i = 1; i < strs.size(); i++)
    sstr << "," << toString(strs[i]);
  sstr << "]";
  return sstr.str();
}

string toString_Matrix(vector<vector<int>> &matrix){
  if (matrix.empty()) return "[[]]";
  std::stringstream sstr;
  sstr << "[" << toString(matrix[0]);
  for (size_t i = 1; i < matrix.size(); i++)
    sstr << ",\n " << toString(matrix[i]);
  sstr << "]";
  return sstr.str();
}

ListNode* createLinkedList(vector<int> &nums) {
  if(nums.empty()) return nullptr;
  ListNode *head = new ListNode(nums[0]);
  ListNode *ptr = head;
  for (size_t i = 1; i < nums.size(); i++){
    ptr->next = new ListNode(nums[i]);
    ptr = ptr->next;
  }
  return head;
}

vector<vector<int>> createSimpleMatrix(size_t r, size_t c){
  vector<vector<int>> m;
  int num = 1;
  for (size_t i = 0; i < r; i++){
    vector<int> row;
    for (size_t j = 0; j < c; j++) row.push_back(num++);
    m.push_back(row);
  }
  return m;
}

vector<int> createVector_Default(size_t n){
  vector<int> v;
  int num = 1;
  for (size_t i = 0; i < n; i++){
    v.push_back(num++);
  }
  return v;
}

vector<int> createVector_Random(size_t n){
  vector<int> v = createVector_Default(n);
  auto rd = std::random_device {}; 
  auto rng = std::default_random_engine { rd() };
  std::shuffle(std::begin(v), std::end(v), rng);
  return v;
}

#if 0
/* Can only deal with no-cycle linkedlist. */
void deleteLinkedList(ListNode *head){
  if (head == nullptr) return;
  ListNode *next_ptr = head->next;
  delete head;
  deleteLinkedList(next_ptr);
}
#endif

void deleteLinkedList(ListNode *head){
  if (head == nullptr) return;
  set<ListNode*> set_node;
  while (head != nullptr) {
    if (set_node.find(head) != set_node.end()) break;
    set_node.insert(head);
    head = head->next;
  }
  for (set<ListNode*>::iterator it = set_node.begin(); it != set_node.end(); it++){
    ListNode *ptr = *it;
    delete ptr;
  }
}

ListNode* getRearPtr(ListNode *head){
  if (head == nullptr) return nullptr;
  while(head->next != nullptr){
    head = head->next;
  }
  return head;
}

string toString(ListNode *head){
  if (head == nullptr) return "[]";
  map<ListNode*, int> node_recorder;
  std::stringstream sstr;
  sstr << "<" << head->val;
  int counter = 0;
  node_recorder[head] = counter;
  head = head->next;
  while (head != nullptr) {
    map<ListNode*, int>::iterator it = node_recorder.find(head);
    if (it != node_recorder.end()){
      sstr << "[c:" << it->second << "]";
      break;
    }
    sstr << "," << head->val;
    counter += 1;
    node_recorder[head] = counter;
    head = head->next;
  }
  sstr << ">";
  return sstr.str();
}

string toString_Graph(Node *node){
  if (node == nullptr) return "Graph: {}";
  int counter = 0;
  map<Node*, int> map_node2id;
  queue<Node*> queue_wait;
  queue_wait.push(node);
  while(!queue_wait.empty()){
    Node *t_node = queue_wait.front();
    queue_wait.pop();
    if(map_node2id.find(t_node) != map_node2id.end()){
      continue;
    }
    vector<Node*> &t_neighbors = t_node->neighbors;
    map_node2id[t_node] = counter++;
    for (size_t i = 0; i < t_neighbors.size(); i++){
      if(map_node2id.find(t_neighbors[i]) == map_node2id.end()){
        queue_wait.push(t_neighbors[i]);
      };
    }
  }
  std::stringstream sstr;
  sstr << "Graph: {\n";
  for (auto it = map_node2id.begin(); it != map_node2id.end(); it++){
    sstr << "\t" << it->first->val << "[" << it->second << "]:[";
    for (size_t i = 0; i < it->first->neighbors.size(); i++){
      sstr << map_node2id[it->first->neighbors[i]] << ",";
    }
    sstr << "],\n";
  }
  sstr << "}\n";
  return sstr.str();
}

void deleteGraph(Node *node){
  std::cout << "delete Graph"<< std::endl;
  if (node == nullptr) return;
  set<Node*> set_deleted;
  queue<Node*> queue_wait;
  queue_wait.push(node);
  while(!queue_wait.empty()){
    Node *t_node = queue_wait.front();
    queue_wait.pop();
    if(set_deleted.find(t_node) != set_deleted.end()){
      continue;
    }
    vector<Node*> &t_neighbors = t_node->neighbors;
    for (size_t i = 0; i < t_neighbors.size(); i++){
      if(set_deleted.find(t_neighbors[i]) == set_deleted.end()){
        queue_wait.push(t_neighbors[i]);
      };
    }
    set_deleted.insert(t_node);
    std::cout << "delete node"<< std::endl;
    delete t_node;
  }
}

string toString_Preorder(TreeNode *root){
  if (root == nullptr) return "()";
  std::stringstream sstr;
  sstr << "(" << root->val;
  if (root->left != nullptr || root->right != nullptr){
    sstr << toString_Preorder(root->left) << toString_Preorder(root->right);
  }
  sstr << ")";
  return sstr.str();
}

string toString_Inorder(TreeNode *root){
  if (root == nullptr) return "()";
  std::stringstream sstr;
  sstr << "(";
  if (root->left == nullptr && root->right == nullptr){
    sstr << root->val << ")";
    return sstr.str();
  }
  sstr << toString_Inorder(root->left) << root->val << toString_Inorder(root->right) << ")";
  return sstr.str();
}

TreeNode* createBinaryTree(vector<int> &nums){
  if (nums.size() == 0) return nullptr;
  TreeNode *root = new TreeNode(nums[0]);
  for (size_t i = 1; i < nums.size(); i++) insertBinaryTree(root, nums[i]);
  return root;
}

void deleteBinaryTree(TreeNode *root){
  if (root == nullptr) return;
  deleteBinaryTree(root->left);
  deleteBinaryTree(root->right);
  delete root;
  return;
}

void insertBinaryTree(TreeNode *root, int element){
  if (root == nullptr) return;
  TreeNode **search_ptr = &root;
  while (*search_ptr != nullptr){
    search_ptr = (element > (*search_ptr)->val)? &(*search_ptr)->right: &(*search_ptr)->left;
  }
  *search_ptr = new TreeNode(element);
}

void insertBinaryTree(TreeNode **root, int element){
  if (root == nullptr) return;
  TreeNode **search_ptr = root;
  while (*search_ptr != nullptr){
    search_ptr = (element > (*search_ptr)->val)? &(*search_ptr)->right: &(*search_ptr)->left;
  }
  *search_ptr = new TreeNode(element);
}


TreeNode* createAVLTree(vector<int> &nums) {
  TreeNode *root = nullptr;
  for (int &element: nums){
    // std::cout << "  insert: " << element << std::endl;
    pair<TreeNode*, bool> insert_result = insertAVLTree(root, element);
    root = insert_result.first;
    // std::cout << "   > preorder: " << toString_Preorder(root) << std::endl;
  }
  return root;
}

TreeNode* createAVLTree(ListNode* head) {
  TreeNode *root = nullptr;
  while(head != nullptr){
    pair<TreeNode*, bool> insert_result = insertAVLTree(root, head->val);
    root = insert_result.first;
    head = head->next;
  }
  return root;
}

#if 0
TreeNode* insertAVLTree(TreeNode *root, int element){
  if (root == nullptr) {
    root = new TreeNode(element);
  } else if (element < root->val) {
    root->left = insertAVLTree(root->left, element);
    root = balanceAVLTree(root);
  } else {
    root->right = insertAVLTree(root->right, element);
    root = balanceAVLTree(root);
  }
}
#endif

pair<TreeNode*, bool> insertAVLTree(TreeNode *root, int element){
  if (root == nullptr) {
    root = new TreeNode(element);
    return {root, false};
  } 
  pair<TreeNode*, bool> insert_result = {nullptr, false};
  if (element < root->val) {
    insert_result = insertAVLTree(root->left, element);
    root->left = insert_result.first;
  } else {
    insert_result = insertAVLTree(root->right, element);
    root->right = insert_result.first;
  }
  if (!insert_result.second){
    TreeNode *new_root = balanceAVLTree(root);
    if (root != new_root) {
      root = new_root;
      return {root, true};
    }
    return {root, false};
  }
  return {root, true};
}

TreeNode* balanceAVLTree(TreeNode *root){
  if (root == nullptr) return root;
  int balance_factor = getHeight(root->left) - getHeight(root->right);
  if (balance_factor > 1){
    balance_factor = getHeight(root->left->left) - getHeight(root->left->right);
    if (balance_factor > 0) return rotation_LL(root);
    else return rotation_LR(root);
  } else if (balance_factor < -1) {
    balance_factor = getHeight(root->right->left) - getHeight(root->right->right);
    if (balance_factor > 0) return rotation_RL(root);
    else return rotation_RR(root);
  }
  return root;
}

TreeNode* rotation_LL(TreeNode *root){
  TreeNode *new_root = root->left;
  root->left = new_root->right;
  new_root->right = root;
  return new_root;
}

TreeNode* rotation_LR(TreeNode *root){
  TreeNode *new_root = root->left->right;
  root->left->right = new_root->left;
  new_root->left = root->left;
  root->left = new_root->right;
  new_root->right = root;
  return new_root;
}

TreeNode* rotation_RL(TreeNode *root){
  TreeNode *new_root = root->right->left;
  root->right->left = new_root->right;
  new_root->right = root->right;
  root->right = new_root->left;
  new_root->left = root;
  return new_root;
}

TreeNode* rotation_RR(TreeNode *root){
  TreeNode *new_root = root->right;
  root->right = new_root->left;
  new_root->left = root;
  return new_root;
}

int getHeight(TreeNode *root){
  if (root == nullptr) return 0;
  return 1 + MAX(getHeight(root->left), getHeight(root->right));
}

#endif /* __LEETCODE_UTILS__ */