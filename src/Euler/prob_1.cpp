#include <bits/stdc++.h> 
using namespace std;

int main(int argc, char *argv[])
{
  int n = 1000;
  int sum = 0;
  for (int i = 3; i < n; i+=3){
    sum += i;
  }

  for (int i = 5; i < n; i+=5){
    if (i % 3 != 0)
      sum += i;
  }

  cout << sum << endl;
  
  return 0;
}
