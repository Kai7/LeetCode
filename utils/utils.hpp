#ifndef __LEETCODE_UTILS__
#define __LEETCODE_UTILS__

#include <iterator>
#include <sstream>
#include <algorithm>
#include <random>

#include "data_structure.hpp"

TreeNode* createBinaryTree(vector<int> &nums);
void insertBinaryTree(TreeNode *root, int element);
void insertBinaryTree(TreeNode **root, int element);
void deleteLinkedList(ListNode *head);

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

#endif /* __LEETCODE_UTILS__ */