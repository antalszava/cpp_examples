#include <bits/stdc++.h> 
using namespace std;

//1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

int main(int argc, char *argv[])
{
  int b1 = 1;
  int b2 = 1;
  int sum = 0;
  for (int i = 0; i < 4000000; i++){
    int temp = b2;
    b2 = b1 + b2;
    b1 = b2;
    if (b2 >= 4000000)
      break;

    if (b2 % 2 == 0){
      sum += b2;
    }
  }

  std::cout << sum << std::endl;
  return 0;
}
