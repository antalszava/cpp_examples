#include <bits/stdc++.h>


void PrintInBinary(unsigned n)
{
  short int iPos;  
  for (iPos = 31 ; iPos >= 0 ; iPos--)
    {
       (n & (1 << iPos)) ? std::cout << "1" : std::cout << "0";	
    }
  std::cout << std::endl;
}

class Solution {
public:
    
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (int i = 31; i >=0; i--){
	  count += ((n & (1 << i)) != 0);	    
        }
        return count;
    }
};


int main(int argc, char *argv[])
{
  int bin = 0b010101010;
  PrintInBinary(bin);
  std::cout << Solution().hammingWeight(bin) << std::endl;
  return 0;
}
