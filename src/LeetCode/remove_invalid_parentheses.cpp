#include <string>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <string.h>
// #include <queue>

bool is_valid(const std::string & str){

  std::stack<char> left;
  if (str.size() == 0){
    return 1;
  }

  // if (str.size() % 2 != 0){
      // return 0;
  // }
  
  
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
    // else {
      // return 0;
    // }
  }

  if (left.size() == 0){
    return 1;
  }
  else{
    return 0;
  }
}

std::vector<string> remove_from_invalid(const std::string & str){

  std::stack<char> left;
  std::queue<char> right;

  str::vector<string> valid_substrings;

  int left_count == 0;
  int right_count == 0;
  
  for (int i = 0; i < str.size(); i++){
    if (str[i] == '(' ||
	str[i] == '{' ||
	str[i] == ']'){
      left_count++;
    }
    if (str[i] == ')' ||
	str[i] == '}' ||
	str[i] == ']'){
      right_count++;
    }  
  }
  int diff = abs(left_count - right_count);

  if (left_count > right_count){
    //try remove all left string combinations until valid
  }

  if (right_count > left_count){

  }
  
  return valid_strings;
}



int main(int argc, char *argv[])
{
  std::cout << is_valid("(aaaa){2}[") << std::endl;
  return 0;
}
