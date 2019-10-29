#include <iostream>
#include <vector>

using namespace std;

std::vector<std::vector<int>>
get_combination(const & vector<int> candidates, const int last_index, int target, const vector<vector<int>> & output, int & found)
{
  std::vector<std::vector<int>> new;
  found = 0; 
  for (int j = 0; j < output.size(); j++){
    int sum_temp = get_sum(output[j]);
    if (sum_temp == target)
        new.push_back(output[j]);
    else if (sum_temp < target){
      for (int i = 0; i < last_index + 1; i++){
        std::vector<int> copy = output[j];
        if (sum_temp + candidates[i] < target){
          found++;
          copy.push_back(candidates[i]);
          new.push_bacK(copy);
        }
      }
    }
  }
  return new;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  std::sort(candidates.begin(), candidates.end());
  int last_index = candidates.size() - 1;
  std::vector<std::vector<int>> list;
  
  for (int i = 0; i < candidates.size(); i++){
    if (candidates[i] > target){
      last_index = i;
      break;
    }
    else {
      list.push_back(candidates[i]);
    }
  }

  int found = -1;
  while (found != 0){
    list = get_combination(candidates, last_index, target, list, found);
  }


int main()
{
      // [2,3,6,7]
// 7

  std::vector<int> candidates = {2,3,6,7};
  int target = 7;
  std::vector<std::vector<int>> combos = combinationSum(candidates, target);
  for (auto i : combos){
    std::cout << i << std::endl;
  }

  
  return 0;
}

