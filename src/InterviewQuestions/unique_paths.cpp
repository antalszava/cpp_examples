#include <iostream>
#include <vector>

int unique_paths(int m, int n){

  std::vector<std::vector<int>> paths(m, std::vector<int>(n));

  for (int i = 0; i < m; ++i){
    paths[i][0] = 1;
  }
  
  for (int j = 0; j < n; ++j){
    paths[j][0] = 1;
  }
  
  for (int i = 1; i < m; ++i){
    for (int j = 1; j < n; ++j){
      paths[i][j] = paths[i-1][j] + paths[j-1][i];
      std::cout << paths[i][j] << std::endl;
    }
  }

  return paths[m-1][n-1];
  
}

int main(int argc, char *argv[])
{
  std::cout << "Number of unique paths for 7x7 grid = " << unique_paths(7,7) << std::endl;
  return 0;
}
