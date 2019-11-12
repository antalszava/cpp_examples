#include <bits/stdc++.h>

bool getBit(int num, int i) {
  return num & (1 << i);
}

int setBit(int num, int i){
  return num | (1 << i);
}

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
    uint32_t reverseBits(uint32_t n) {
      uint32_t tmp = 0;
      for (int iPos = 31; iPos >= 0; iPos--){
	if (getBit(n,iPos))
	  tmp = setBit(tmp, 31-iPos);
      }
      return tmp;
    }
};

int main(int argc, char *argv[])
{
  if (argc != 2) {
    std::cout << "argc != 2" << std::endl;
    exit(1);
  }
  int num = atoi(argv[1]);

  PrintInBinary(num);
  PrintInBinary(Solution().reverseBits(num));
  // iPos = 2;
  // std::cout << (32 & (1 << iPos)) << std::endl;
  // PrintInBinary(num);
  return 0;
}
