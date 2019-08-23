#include "stdlib.h"
#include <vector>
#include <algorithm>

int cmp(const void* a, const void* b)
{
  if(*(int*)a < *(int*)b)
    return -1;
  else if(*(int*)a > *(int*)b)
    return 1;
  else 
    return 0;  
}

int main(int argc, char**argv)
{
  auto lim = atoi(argv[1]);

  std::vector<int> vec;
  vec.reserve(lim);

  while(lim--)
    vec.push_back(random());

  if(*argv[2]=='q')
    qsort(&vec[0], vec.size(), sizeof(int), cmp);
  else if(*argv[2]=='p')
    std::sort(vec.begin(), vec.end()); 
  else if(*argv[2]=='s')
    std::sort(vec.begin(), vec.end());
}
