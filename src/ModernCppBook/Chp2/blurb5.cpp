#include <initializer_list>
class MagicFoo {
public:
  std::vector<int> vec;
  MagicFoo(std::initializer_list<int> list){
    for (std::initializer_list<int>::iterator it = list.begin(); it != list.end(); ++it)
      vec.push_back(*it);
  }

  void foo(std::initializer_list<int> list){
    for (std::initializer-list<int>::iterator it = list.begin(); it != list.end(); ++it) vec.push_back(*it);
  }

};

int main() {

  MagicFoo magicFoo = {1,2,3,4,5};
  std::cout << "magicFoo: ";
  for (std::vector<int>::iterator it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it) std::cout << *it << std::endl;
  magicFoo.foo({6,7,8,9});
  
}
