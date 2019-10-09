//variadic templates

#include <iostream>

template < typename ... Ts >
void magic (Ts ... args) {
  std :: cout << sizeof ...( args) << std :: endl;
}


int main(int argc, char *argv[])
{

  magic (1, "");
  return 0;
}
