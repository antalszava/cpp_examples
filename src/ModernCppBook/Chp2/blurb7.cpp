#include <initializer_list>
#include <vector>
#include <iostream>

class MagicFoo {
public:
  std::vector<int> vec;
  MagicFoo(std::initializer_list<int> list){
    for (auto it = list.begin(); it != list.end(); ++it){
      vec.push_back(*it);
    }
  }

};

int main() {

  MagicFoo magicFoo = {1,2,3,4,5};
  std::cout << "magicFoo: ";
  for (auto it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it){
    std::cout << *it << ", ";
  }
  std::cout << std::endl;

  auto i = 5; //i is int
  auto arr = new auto(10); // arr as int*
  return 0;
}
