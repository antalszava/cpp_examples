#include <bits/stdc++.h>
using namespace std;

class Solution {
public:    
    bool checksubstring(string s, int i, int j){
        for (int k = i; k <= i + (j-i)/2; k++){
            if (s[k] != s[j - k + i]) 
                return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        for (int i = 0; i < s.size()/2; i++){
            if (s[i] != s[s.size()-1-i]){                
                return checksubstring(s, i+1, s.size()-1-i) || checksubstring(s,i, s.size()-2-i);
            }
        }
        return true;
    }
};


int main(int argc, char *argv[])
{
  std::cout << Solution().validPalindrome("abbca") << std::endl;
  return 0;
}
