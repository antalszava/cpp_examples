#include <bits/stdc++.h>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0)
            return false;
        
        if (n != 1 && n % 2 != 0)
            return false;
        
        int count = 0;
        
        for (int i = 0; i < 32; i++){
	        count += ((n & (1 << i)) != 0);	    
            if (count > 1)
                return 0;
        }
        
        return count == 1;
    }
    
};


int main(int argc, char *argv[])
{
  std::cout << Solution().isPowerOfTwo(213213) << std::endl;
  return 0;
}

