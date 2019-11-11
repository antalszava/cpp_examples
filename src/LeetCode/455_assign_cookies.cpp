#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int findContentChildren(vector<int> && g, vector<int> && s) {
    if(s.size() == 0 || g.size() == 0)
      return 0;
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());
    int cc = 0;

        
    int j = 0;
    for (int i = 0; i < s.size(); i++){
      if (s[i] >= g[j]){
	cc++;
	j++;
	if (j > g.size()-1) break;
      }

    }   
    return cc;
  }
};

int main(int argc, char *argv[])
{
  std::cout << Solution().findContentChildren(vector<int>{1, 2, 3, 4}, vector<int>{1, 2, 3, 4}) << std::endl;
  return 0;
}

