#include "solver.hpp"
#include "utils/data_structure.hpp"
#include "utils/utils.hpp"

void runSample(vector<vector<int>>& grid){
  std::cout << "Input: grid = " << std::endl << toString_Matrix(grid) << std::endl;
  Solution solver;
  int ans = solver.minPathSum(grid);
  std::cout << "Output: " << ans << std::endl << std::endl;
}

int main(){
  vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};

  runSample(grid);

  return 0;
}