#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void mark_island(vector<vector<char>>& grid, int i, int j){
        grid[i][j] = 'x';
        if (i+1 < grid.size() && grid[i+1][j] == '1')
            mark_island(grid,i+1,j);
        if (j+1 < grid[0].size() && grid[i][j+1] == '1')
            mark_island(grid,i,j+1);
        if (i-1 >= 0 && grid[i-1][j] == '1')
            mark_island(grid,i-1,j);
        if (j-1 >= 0 && grid[i][j-1] == '1')
            mark_island(grid,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == '1'){
                    mark_island(grid,i,j);
                    count++;
                }
        return count;
    }
};


int main(int argc, char *argv[])
{
  vector<vector<char>> islands = {{'1','1','1'},{'0','1','0'},{'1','1','1'}};
  std::cout << Solution().numIslands(islands) << std::endl;
  return 0;
}
