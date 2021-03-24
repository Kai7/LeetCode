#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(vector<vector<int>>& matrix){
  std::cout << "Input: matrix = " << std::endl << toString_Matrix(matrix) << std::endl;
  Solution solver;
  solver.rotate(matrix);
  std::cout << "Output: " << std::endl << toString_Matrix(matrix) << std::endl << std::endl;
}

int main(){
  // vector<vector<int>> matrix = createSimpleMatrix(1,1);
  // vector<vector<int>> matrix = createSimpleMatrix(2,2);
  // vector<vector<int>> matrix = createSimpleMatrix(3,3);
  // vector<vector<int>> matrix = createSimpleMatrix(4,4);
  // vector<vector<int>> matrix = createSimpleMatrix(5,5);
  // vector<vector<int>> matrix = createSimpleMatrix(10,10);
  vector<vector<int>> matrix = createSimpleMatrix(11,11);

  runSample(matrix);

  return 0;
}