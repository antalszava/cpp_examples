#include <string>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
// #include <queue>

bool is_valid(const std::string & str){

  std::stack<char> left;
  if (str.size() == 0){
    return 1;
  }

  for (int i = 0; i < str.size(); i++){
    if (str[i] == '('){
      left.push(')');
    }
    else if (str[i] == '[') {
      left.push(']');
    }
    else if (str[i] == '{') {
      left.push('}');
    }
    else if (str[i] == ')' ||
	     str[i] == '}' ||
	     str[i] == ']'){
      if (left.size() == 0){
	return 0;
      }
      else if (str[i] == left.top()){
	left.pop();
      }
      else {
	return 0;
      }
    }
  }

  if (left.size() == 0){
    return 1;
  }
  else{
    return 0;
  }
}


int is_valid_char(const std::string & str, char left_char, char right_char){
  if (str.size() == 0){
    return 0;
  }
  int left_count = 0;
  int right_count = 0;
  
  for (int i = 0; i < str.size(); i++){
    if (str[i] == left_char){
      left_count++;
    }
    if (str[i] == right_char){
      right_count++;
    }  
  }
  return left_count - right_count;
}

std::set<std::string> remove_char_from_strings
(
 const std::set<std::string> & strs,
 int num_rem,
 char rem
)
{
  
  std::set<std::string> ret_strs;
  for (auto i : strs){
    for (int j = 0; j < i.size(); j++){
      if (i[j] == rem){
	std::string str = i;
	str.erase(j, 1);
	ret_strs.insert(str);
      }
    }
  }


  // std::cout << std::endl;
  // std::cout << "REMOVE_CHAR_FROM_STRINGS" << std::endl;
  // for (int i = 0; i < strs.size(); i++){
  //     std::cout << strs[i] << std::endl;
  // }
  // std::cout << "char = " << rem << std::endl;
  // std::cout << "num_rem = " << num_rem << std::endl;
  // for (int i = 0; i < ret_strs.size(); i++){
  //     std::cout << ret_strs[i] << std::endl;
  // }
  // std::cout << std::endl;

  
  if (num_rem > 1){
    ret_strs = remove_char_from_strings(ret_strs, num_rem - 1, rem);
  }
  return ret_strs;
}

int main(int argc, char *argv[])
{

  std::string str("[[]]](aaaa){2}[[]]]");
  std::set<std::string> strings;
  strings.insert(str);
  
  // std::cout << is_valid("(aaaa){2}[") << std::endl;
  int diff0 = is_valid_char(str, '(', ')');
  if (diff0 != 0)
    strings = remove_char_from_strings(strings, abs(diff0), (diff0 > 0) ? '(' : ')');
  
  int diff1 = is_valid_char(str, '{', '}');
  if (diff1 != 0)
    strings = remove_char_from_strings(strings, abs(diff1), (diff1 > 0) ? '{' : '}');
  
  int diff2 = is_valid_char(str, '[', ']');
  if (diff2 != 0)
    strings = remove_char_from_strings(strings, abs(diff2), (diff2 > 0) ? '[' : ']');
  

  std::cout << "FINISHED" << std::endl;
  for (auto i : strings){
    if (is_valid(i)){
      std::cout << i << std::endl;
    }
  }
  
  return 0;
}
