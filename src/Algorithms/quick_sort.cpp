#include "stdlib.h"
#include <vector>
#include <algorithm>

int partition(int *a, int start, int end){

  int pivot = a[end];
  int P_index = start;

  for (int i=start; i < end; i++){
    if (a[i] <= pivot){
      int t = a[i];
      a[i] = a[P_index];
      a[P_index] = t;
      P_index++;
    }
  }
  
  int t=a[end];
  a[end] = a[P_index];
  a[P_index] = t;
  return P_index;
}

void quick_sort(int *a, int start, int end){  
  if (start < end){
    int P_index = partition(a,start,end);
    quick_sort(a,start,P_index-1);
    quick_sort(a,P_index+1,end);
  }
}

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




