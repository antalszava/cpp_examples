#include <string>
#include <vector>
#include <iostream>

std::string longest_common_prefix(const std::vector<std::string>& strs)
{
  int i = 0;
  std::string lcp("");

  if {strs.size() == 0}{
    return lcp;
  }

  if (strs.size() == 1){
    return strs[0];
  }
  
  for (int i = 0; i < strs[0].size(); i++){
    for (int j = 1; j < strs.size(); j++){
      if(strs[j][i] != strs[0][i]){
	return lcp;
      }
    }
    lcp += strs[0][i];
  }
  
  return lcp;
}

int main(int argc, char *argv[])
{
  std::cout << longest_common_prefix(std::vector<std::string>({"flower","flow","flight"})) << std::endl;
  return 0;
}


