#ifndef SINGLETON_H
#define SINGLETON_H 
class S
{
public:
  /* Will be properly destroyed */
  static S& getInstance()
  {
    static S instance;
    return instance;
  }

  /* C++11 */
  S(S const&) = delete;
  void operator=(S const&) = delete;
  
private:
  S() {};
}

#endif
