/**
 * @file   first_occurrence.cpp
 * 
 * @brief  Given a sorted array, use a binar
 * search to find the first occurence of a number
 * and return first index, otherwise -1
 * 
 */

#include <iostream>
#include <vector>

int first_occurrence
(
 const std::vector<int> & vec,
 const int key
)
{
  int high = vec.size() - 1;
  int low = 0;
  int first_occurrence = -1;
  while(low <= high){
    int mid = (high + low) / 2;
    if (key < vec[mid]) {
      high = mid -1;
    }
    else if (key > vec[mid]){
      low = mid + 1;
    }
    else {
      first_occurrence = mid;
      high = mid - 1;
    }
  }
  return first_occurrence;
}

void print_vec(const std::vector<int> & vec){
  for (auto & i : vec){
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

int main()
{
  std::vector<int> vec{ 1, 1, 1, 1, 2, 2, 3, 3, 3};
  std::cout << "Contents of vector:\n";
  print_vec(vec);
  std::cout << "First occurrence of 3 in the vector is at index: "
            << first_occurrence(vec, 3) << "\n";
  return 0;
}
