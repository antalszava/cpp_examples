#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[])
{
  std::vector<int> vec = {1,2,3,4};
  if (auto itr = std::find(vec.begin(), vec.end(), 3); itr != vec.end()) *itr = 4;

  for (auto element : vec){
    std::cout << element << std::endl; //read only
  }

  for (auto &element : vec) {
    element += 1; // writeable;
  }
  
  return 0;
}
