#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(vector<vector<int>>& matrix, int target){
  std::cout << "Input: matrix = \n" << toString_Matrix(matrix) << ", target = " << target << std::endl;
  Solution solver;
  bool ans = solver.searchMatrix(matrix, target);
  std::cout << "Output: " << toString(ans) << std::endl << std::endl;
}

int main() {
  // vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
  // vector<vector<int>> matrix = {{1}};
  // vector<vector<int>> matrix = {{1,3,15,30}};
  vector<vector<int>> matrix = {{1},{3},{15},{30}};

  runSample(matrix, 0);
  runSample(matrix, 1);
  runSample(matrix, 7);
  runSample(matrix, 8);
  runSample(matrix, 15);
  runSample(matrix, 16);
  runSample(matrix, 60);
  runSample(matrix, 66);

  return 0;
}