#include <vector>
#include <random>
#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>

template <typename T>
bool is_pair_sum(std::vector<T> A, T sum)
{
    // represents first pointer
    int i = 0;
 
    // represents second pointer
    int j = A.size() - 1;
 
    while (i < j) {
 
        // If we find a pair
        if (A[i] + A[j] == sum)
            return true;
 
        // If sum of elements at current
        // pointers is less, we move towards
        // higher values by doing i++
        else if (A[i] + A[j] < sum)
            i++;
 
        // If sum of elements at current
        // pointers is more, we move towards
        // lower values by doing i++
        else
            j--;
    }
    return false;
}


int main(){

  // First create an instance of an engine.
  std::random_device rnd_device;
  // Specify the engine and distribution.
  std::mt19937 mersenne_engine {rnd_device()};  // Generates random integers
  std::uniform_int_distribution<int> dist {1, 52};

  auto gen = [&dist, &mersenne_engine](){
	       return dist(mersenne_engine);
	     };

  std::vector<int> vec(10);
  generate(begin(vec), end(vec), gen);
  bool is_pair = is_pair_sum(vec, 34);
  std::cout << "is_pair " << is_pair << std::endl;
  return 0;
}
