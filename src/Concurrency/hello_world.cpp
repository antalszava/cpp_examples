#include <iostream>
#include <thread>

void hello()
{
  std::cout << "Hello Concurrent World\n";
}

int main(int argc, char *argv[])
{
  //each thread must have a "main function" that is sent to the thread
  //via the constructor
  std::thread t(hello);

  //join causes the calling thread to wait for the thread associated
  //with the std::thread object otherwise the main thread will end the program
  t.join(); 
  
  return 0;
}
