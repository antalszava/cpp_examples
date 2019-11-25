#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid){

      vector<int> row_sums(grid.size(),0);
      vector<int> column_sums(grid[0].size(),0);
      
      for (int i = 0; i < grid.size(); i++){
	for (int j = 0; j < grid[i].size(); j++){
	  row_sums[i] += grid[i][j];
	  column_sums[j] += grid[i][j];
	}
      }

      int count = 0;
      for (int i = 0; i < grid.size(); i++){
	for (int j = 0; j < grid[i].size(); j++){
	  if (grid[i][j] == 1 && (row_sums[i] > 1 || column_sums[j] > 1)){
	    count++;
	  }
	}
      }
      
      return count;
    }
};


 
int main(int argc, char *argv[])
{
  // std::cout << "fuck you " << std::endl;
  std::vector<vector<int>> points = {{1,0,0},{1,1,0},{0,0,1}};
  cout << Solution().countServers(points) << endl;
  return 0;
}
