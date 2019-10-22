
#include <string>
#include <vector>
#include <iostream>


std::string countAndSay(int n) {
  if (n == 0)
    return std::string("");  
  std::vector<std::string> strs(n);
  strs[0] = "1";
  if (n == 1)
    return strs[0];        
  for (int i = 1; i < n; i++){
    std::string old = strs[i-1];
    char old_char = strs[i-1][0];
    int j = 1;
    int count = 1;
    while(j < strs[i-1].size()){
      if (strs[i-1][j] == old_char){
	count++;
      }
      else {
	strs[i].append(std::to_string(count) + old_char);    
	old_char = strs[i-1][j];
	count = 1;
      }
      j++;
    }
    strs[i].append(std::to_string(count) + old_char);
  }
  return strs[strs.size() - 1];
}



int main(int argc, char *argv[])
{
  std::cout << countAndSay(6) << std::endl;
  return 0;
}
