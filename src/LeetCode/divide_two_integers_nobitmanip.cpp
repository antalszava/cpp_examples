#include <iostream>
#include <cmath>
#include<bits/stdc++.h> 

int divide(int dividend, int divisor) {
  int neg_flag = 0;
  double dividend_dbl = dividend;
  double divisor_dbl = divisor;
        
            
  if (dividend_dbl < 0 && divisor_dbl < 0){
    dividend_dbl = -dividend_dbl;
    divisor_dbl = -divisor_dbl;
  }
  else if(dividend_dbl < 0 && divisor_dbl > 0){
    neg_flag = 1;
    dividend_dbl = -dividend_dbl;
  }
  else if (dividend_dbl > 0 && divisor_dbl < 0){
    neg_flag = 1;
    divisor_dbl = -divisor_dbl;
  }

        
        
  double result = exp(log(dividend_dbl) - log(divisor_dbl));
  result = (neg_flag == 1) ? -result : result;


  std::cout << std::setprecision(20);
  std::cout << neg_flag << std::endl;

  std::cout << dividend_dbl << std::endl;
  std::cout << divisor_dbl << std::endl;

  std::cout << result << std::endl;

        
  if (round(result) > INT_MAX || round(result) < INT_MIN){
    return INT_MAX;
  }
  else {
    return result;
  } 
        
        
  //return (neg_flag == 1) ? -result : result; 
}

int main(int argc, char *argv[])
{

  std::cout << divide(-2147483648,1) << std::endl;
  std::cout << INT_MIN << std::endl;
 
  
  return 0;
}

