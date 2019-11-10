#include <vector>
#include <iostream>

using namespace std;

int searchInsert(const vector<int>& nums, int target) {


  int l = 0;
  int r = nums.size() - 1;
  int mid = -1;
  
  while (l <= r){
    mid = (r+l)/2;
    if (nums[mid] > target){
      r = mid - 1;
    }
    else if (nums[mid] < target){
      l = mid + 1;
    }
    else{
      return mid;
    }    
  }
  
  std::cout << mid << std::endl;
  if (mid == 0 && target > nums[0])
    return mid + 1;
  else if (mid <= 0 && target < nums[0])
    return 0;
  else if (mid == nums.size() - 1 && target > nums[nums.size() - 1])
    return mid + 1;
  else
    return mid + 1;

}

int main(int argc, char *argv[])
{
  std::cout << searchInsert(std::vector<int>{1,3}, 2) << std::endl;
  return 0;
}
