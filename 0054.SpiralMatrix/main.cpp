#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(vector<vector<int>>& matrix){
  std::cout << "Input: matrix = " << toString_Matrix(matrix) << std::endl;
  Solution solver;
  vector<int> ans = solver.spiralOrder(matrix);
  std::cout << "Output: " << toString(ans) << std::endl << std::endl;
}

int main(){
  // vector<vector<int>> matrix = createSimpleMatrix(3,4);
  // vector<vector<int>> matrix = createSimpleMatrix(1,1);
  // vector<vector<int>> matrix = createSimpleMatrix(1,2);
  vector<vector<int>> matrix = createSimpleMatrix(2,2);

  runSample(matrix);

  return 0;
}