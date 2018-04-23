#include <set>
#include <string>
#include <iostream>

int main()
{
  // Set<> is a class which implements Set which means that it store only unique elements. Set<> is implemented using a red-black balanced binary search tree in C++ Collections. Since Set<> is implemented using a binary search tree its elements are stored in sequential order.
  std::set<std::string> ts;
 
  // Add elements to the hash set.
  ts.insert("India");
  ts.insert("USA");
  ts.insert("Brazile");
  ts.insert("Canada");
  ts.insert("UK");
  ts.insert("China");
  ts.insert("France");
  ts.insert("Spain");
  ts.insert("Italy");
 
  for (auto var : ts)
    {
      std::cout << var << " ";
    }
  std::cout << std::endl;
  
  ts.erase("USA");
  for (auto var : ts)
    {
      std::cout << var << " ";
    }
  std::cout << std::endl;
  return 0;
}
