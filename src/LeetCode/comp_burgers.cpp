#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numOfBurgers(int t, int ch) {
      // double a = 4;
      // double b = 2;
      // double c = 1;
      // double d = 1;
      // double determinant = a*d - b*c;
      
      int x = round((t-2*ch)*.5);
      int y = round((4*ch-t)*.5);
      // cout << determinant << endl;
      // cout << x << endl;
      // cout << y << endl;
      
      if (x*4 + y*2 == t && x + y == ch && x >= 0 && y >= 0){
        return vector<int>{(int)x,(int)y};
      }
      else {
	return vector<int>();
      }
    }
};

int main(int argc, char *argv[])
{
  // std::vector<vector<int>> points = {{0,0},{1,1},{0,1},{0,2},{1,0},{2,0}};
  // std::vector<vector<int>> points = {{0,0},{1,1},{2,0},{1,0},{1,2},{2,1},{0,1},{0,2},{2,2}};

  
  vector<int> sol = Solution().numOfBurgers(0,0);
  if (sol.size() != 0) {
    cout << sol[0] << " " << sol[1] << endl;
  }
  return 0;
}
