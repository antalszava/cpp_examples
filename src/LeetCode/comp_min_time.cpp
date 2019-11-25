#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int find_time_between_two_points(vector<int> &p1, const vector<int> &p2) {

    int x_neg,y_neg;
    int x_diff = p2[0] - p1[0];
    int y_diff = p2[1] - p1[1];
    int time = 0;
    while (abs(x_diff) != 0 || abs(y_diff) != 0){

      std::cout << x_diff << endl;
      cout << y_diff << endl;
      if (abs(x_diff) >= 1 && abs(y_diff) >= 1){
	if (p2[0] > p1[0]){
	  p1[0] += 1;
	}
	else {
	  p1[0] -= 1;
	}
	if (p2[1] > p1[1]){
	  p1[1] += 1;
	}
	else {
	  p1[1] -= 1;
	}
	time++;
      }
      
      else if (abs(x_diff) >=1){
	if (p2[0] > p1[0]){
	  p1[0] += 1;
	}
	else {
	  p1[0] -= 1;
	}
	time++;
      }
      else if (abs(y_diff) >=1){
	if (p2[1] > p1[1]){
	  p1[1] += 1;
	}
	else {
	  p1[1] -= 1;
	}
	time++;
      }
      x_diff = p2[0] - p1[0];
      y_diff = p2[1] - p1[1];
    }
    return time;
  }
  
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {

      int time = 0;
      if (points.size() <= 1){
	return 0;
      }
      
      for (int i = 0; i < points.size() - 1; i++){
	time += find_time_between_two_points(points[i],points[i+1]);
      }
      cout << "time = " << time << endl;
      return time;
    }
};



int main(int argc, char *argv[])
{
  // std::cout << "fuck you " << std::endl;
  std::vector<vector<int>> points = {{1,1},{3,5},{-1,0}};
  Solution().minTimeToVisitAllPoints(points);
  return 0;
}
