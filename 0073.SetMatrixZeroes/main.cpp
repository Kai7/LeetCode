#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(vector<vector<int>>& matrix) {
  std::cout << "Input: matrix = \n" << toString_Matrix(matrix) << std::endl;
  Solution solver;
  solver.setZeroes(matrix);
  std::cout << "Output: \n" << toString_Matrix(matrix) << std::endl << std::endl;
}

int main() {
  vector<vector<int>> matrix = createSimpleMatrix(3,4);
  matrix[0][0] = 0;
  matrix[2][2] = 0;

  runSample(matrix);

  return 0;
}