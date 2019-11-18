#include <bits/stdc++.h>

using namespace std;





class Solution {
public:

  pair<int,int> shift_ij(pair<int,int> ij, int sizei, int sizej){
    int & i = ij.first;
    int & j = ij.second;
    if (i == sizei- 1 && j == sizej - 1)
      return make_pair(0,0);
    else if (i != sizei - 1 && j == sizej - 1)
      return make_pair(i+1, 0);
    else 
      return make_pair(i,j+1);
  }

  pair<int,int> shift_ij_ktimes(pair<int,int> ij, int sizei, int sizej, int k){
    pair<int, int> ij_new = shift_ij(ij, sizei, sizej);
    if (k > 1){
      ij_new = shift_ij_ktimes(ij_new, sizei, sizej, k - 1);
    }
    return ij_new;
  }
  
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    if (k == 0){
      return grid;
    }
    vector<vector<int>> shift_grid = grid;
      for (int i = 0; i < grid.size(); i ++){
	for (int j = 0; j < grid[i].size(); j++) {
	  
	  pair<int,int> ij = make_pair(i,j);
	  pair<int,int> ij_new = shift_ij_ktimes(ij,grid.size(),grid[i].size(), k);
	  // std::cout << "ij = " << ij.first << " " << ij.second << std::endl;
	  // std::cout << "ij_new = " << ij_new.first << " " << ij_new.second << std::endl;
	  shift_grid[ij_new.first][ij_new.second] = grid[i][j];
	}
    }
    return shift_grid;
  }
};




int main(int argc, char *argv[])
{

  int k = 4;
  // vector<vector<int>> matrix = {{3,8,1,9},{19,7,2,5},{4,6,11,10},{12,0,21,13}};
  vector<vector<int>> matrix = {{1}, {2}, {3}, {4}, {7}, {6}, {5}};

  for (int i = 0; i < matrix.size(); i++){
    for(int j = 0; j < matrix[i].size(); j++){
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
    std::cout << std::endl;    std::cout << std::endl;
  vector<vector<int>> shifted_matrix = Solution().shiftGrid(matrix,23);
  
  for (int i = 0; i < shifted_matrix.size(); i++){
    for(int j = 0; j < shifted_matrix[i].size(); j++){
      std::cout << shifted_matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }

  
  return 0;
}
