#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
      int start = 0;

      if (moves.size() < 3){
	return string("Pending");
      }
      
      //first player
      if (moves.size() % 2 == 0){
	start = 1;
      }
      

      int player_win = 0;
      std::vector<int> col_counts(3,0);
      std::vector<int> row_counts(3,0);
      std::vector<int> diag_counts(2,0);
      for (int i = start; i < moves.size(); i += 2){
	row_counts[moves[i][0]]++;
	col_counts[moves[i][1]]++;

	if (row_counts[moves[i][0]] == 3 || col_counts[moves[i][1]] == 3){
	  player_win = 1;
	}

	if (moves[i][0] == moves[i][1]){
	  diag_counts[0]++;
	}
	
	if (moves[i][0] == 2 && moves[i][1] == 0){
	  diag_counts[1]++;
	}

	if (moves[i][0] == 1 && moves[i][1] == 1){
	  diag_counts[1]++;
	}

	if (moves[i][0] == 0 && moves[i][1] == 2){
	  diag_counts[1]++;
	}
	
	// cout << moves[i][0] << " " << moves[i][1] << " " << diag_counts[1] << endl;
	  
	if (diag_counts[0] == 3 || diag_counts[1] == 3){
	  player_win = 1;
	}

    }
	if (start == 0 && player_win == 1){
	  return string("A");
	}
	else if (start == 1 && player_win == 1){
	  return string("B");
	}
	else if (moves.size() == 9){
	  return string("Draw");
	}
	else {
	  return string("Pending");
	}

    }
};


int main(int argc, char *argv[])
{
  // std::vector<vector<int>> points = {{0,0},{2,0},{1,1},{2,1},{2,2}};
  // std::vector<vector<int>> points = {{0,0},{1,1},{0,1},{0,2},{1,0},{2,0}};
  // std::vector<vector<int>> points = {{0,0},{1,1},{2,0},{1,0},{1,2},{2,1},{0,1},{0,2},{2,2}};
  std::vector<vector<int>> points;
  cout << Solution().tictactoe(points) << endl;
  return 0;
}
