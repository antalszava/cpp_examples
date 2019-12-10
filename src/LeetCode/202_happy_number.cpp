#include <bits/stdc++.h> 
using namespace std;


class Solution {
public:
    
    bool isHappy(int n) {
        
        if (n == 1) return true;

	map<int,int> history;
	
        int happy = 0;
        int num = n;
        
        while(num < INT_MAX){
            int temp = num;
            int sum = 0;
            
	    if (history.find(num) != history.end()) return false;
	        history.emplace(std::make_pair(num,1));
            
            while (temp != 0){
                int dig = temp % 10;
                sum += dig*dig;
                temp /= 10;
            }

	    cout << sum << endl;
	    cout << num << endl;

            if (sum == 1) return true;
            //if (sum == n) return false;
            num = sum;
        }
        
        return false;
            
    }
};



int main(int argc, char *argv[])
{
  std::cout << Solution().isHappy(19) << std::endl;
  return 0;
}

