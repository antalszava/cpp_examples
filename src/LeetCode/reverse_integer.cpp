

#include <iostream>


int main(int argc, char *argv[])
{
  long int x = 1534236469;
  long int reversed_number = 0;

  std::cout << " x= " << x << std::endl;
  //  std::cout << " 964632435*10 = " << 964632435*10 << std::endl;
  while(x != 0)
    {
      std::cout << " x = " << x << std::endl;
      long int remainder = x%10;
      std::cout << "remainder = " << remainder << std::endl;
      reversed_number = reversed_number*10 + remainder;
      std::cout << "reversed_number = " << reversed_number << std::endl;
      x /= 10;
    }
  
  std::cout << "reverse number = " << reversed_number << std::endl;

return 0;
}



