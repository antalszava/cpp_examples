#include <iostream>

int char_to_int(char c){
  return  c - '0';
}
    
int myAtoi(string str) {
  int neg_flag = 0;
  int pos_flag = 0;
  int num = 0;
  int hit_a_digit = 0;
  for (int i = 0; i < str.size(); i++){
    if (isdigit(str[i])){
      hit_a_digit++;
      int digit = (char_to_int(str[i]));
      if(neg_flag == 0 && (num > INT_MAX/10 || (num == INT_MAX/10 && digit >= 7)))
	return INT_MAX;
      if(neg_flag == 1 && (-num < INT_MIN/10 || (-num == INT_MIN/10 && digit >= 8)))
	return INT_MIN;
      num = 10*num + digit;
    }
    else if(str[i]=='-'){
      if(hit_a_digit){
	break;                  
      }
      neg_flag++; 

    }
    else if(str[i] == '+'){
      if(hit_a_digit){
	break;                  
      }
      pos_flag++;
    }
    else if(str[i] != ' ' || hit_a_digit > 0 || pos_flag > 0 || neg_flag > 0){
      break;
    }
  }
        
  if (neg_flag + pos_flag > 1)
    return 0;
        
  if (neg_flag > 0)
    return -1*num;
  else
    return num;

}
