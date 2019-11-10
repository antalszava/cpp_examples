#include <iostream>
#include <vector>
#include <algorithm>
int sockMerchant(const std::vector<int> & ar_) {
    int pairs = 0;
    std::vector<int> ar = ar_;
    std::sort(ar.begin(), ar.end());

    int temp = ar[0];
    int temp_count = 1;
    for (auto i : ar){
      std::cout << i;
    }
    std::cout << std::endl;
   
    for (int i = 1; i < ar.size(); i++){
        if (ar[i] == temp){
            temp_count++;
        }
        else {
            pairs += temp_count/2;
            temp = ar[i];
            temp_count = 1;
        }
    }
    pairs += temp_count/2;
    return pairs;
}

int main(int argc, char *argv[])
{
  std::cout << sockMerchant(std::vector<int>({1, 1, 3, 1, 2, 1, 3, 3, 3, 3})) << std::endl;
  return 0;
}
