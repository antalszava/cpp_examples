#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

  const int pow10[10] = {
			 1, 10, 100, 1000, 10000, 
			 100000, 1000000, 10000000, 100000000, 1000000000
  };

  int get_digit(int num, int dig){
    int count = 0;
    int num_dig;
    while (count <= dig){
      num_dig = num % 10;
      num /= 10;
      count++;
    }
    return num_dig;
  }

  
  std::pair<int,int> get_digit_class(int n){
      int count = 0;
      int num = 0;
      int num_old;
      while (num < n){
	count++;
	num_old = num;
	if (count == 9){
	  break;
	}

	num += count*(int)pow10[count]*.9;
      }
      return make_pair(count,num_old);
    }
    
    int findNthDigit(int n) {
      std::pair<int, int> cpair = get_digit_class(n);
      int c = cpair.first;
      if (c == 1) return n;
      int size_digits_prev_class = cpair.second;
      int dig_c_id = n - size_digits_prev_class - 1;
      int num_c_id = dig_c_id/c;
      int local_dig_id_right = c - 1 - dig_c_id % c;
      return get_digit(pow10[c-1] + num_c_id, local_dig_id_right);
    }
};


int main(int argc, char *argv[])
{
  // int bin = 0b010101010;
  // PrintInBinary(bin);
  int n = 1;
  int n_max = 10000;

  // std::cout << "Solution for n = " << n << " is " << Solution().findNthDigit(n) << std::endl;
  
  
  while(n < n_max){
    int digit_count = 0;
    int fast_way = Solution().findNthDigit(n);
    int slow_way = -1;
    for (int i = 1; i <= n; i++){
      digit_count += floor(log10(i))+1;
      if (digit_count >= n){
	slow_way = Solution().get_digit(i,(digit_count - n));
	break;
      }
    }
    if (slow_way != fast_way){
      std::cout << "WRONG n, fast_way, slow_way " << n << " " << fast_way << " " << slow_way << std::endl; 
    }
    std::cout << "CORRECT n, fast_way, slow_way " << n << " " << fast_way << " " << slow_way << std::endl; 
    n++;
  }
  return 0;
}
