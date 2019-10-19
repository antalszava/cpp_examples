#include <vector>
#include <iostream>
#include <string>

using namespace std;
vector<string> lookup = {{"abc"},{"def"},{"ghi"},{"jkl"},{"mno"},{"pqrs"},{"tuv"},{"wxyz"}};  
    
    
vector<string> add_new_combs(const vector<string> & strs, string comb){
  int orig_size = strs.size();
  int comb_size = comb.size();
  std::vector<string> newstrs;
  
  if (strs.size() == 0){
    for (int j = 0; j < comb_size; j++){
      newstrs.push_back(std::string("") + comb[j]);   
    }
  }
  
  for (int i = 0; i < orig_size; i++){
    for (int j = 0; j < comb_size; j++){
      newstrs.push_back(strs[i] + comb[j]);   
    }
  }
  return newstrs;
}
    
vector<string> letterCombinations(string digits) {
  if (digits.size() == 0)
    return vector<string>();
  
  vector<string> strs;
        
  if (digits.size() > 1){
    for (int j = 0; j < digits.size(); j++){
      int digit = atoi((std::string("") + digits[j]).c_str());
      string comb = lookup[digit - 2];
      strs = add_new_combs(strs, comb);
    }
  }        
  return strs;
}

int main(int argc, char *argv[])
{
  std::string digits("2876");
  vector<string> strs = letterCombinations(digits);
  for (auto i : strs){
    std::cout << i << "\n";
  }
  std::cout << "size = " << strs.size() << std::endl;
  return 0;
}
