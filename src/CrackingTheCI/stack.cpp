#include <iostream>
#include <memory>

template <typename T>
class StackNode
{
private:
  T item_;
  std::shared_ptr<StackNode<T>> next_;
public:
  StackNode(T item, std::shared_ptr<StackNode<T>> next) : item_(item), next_(next) {};
  T GetItem(){
    return item_;
  }
  std::shared_ptr<StackNode<T>> GetNext(){
    return next_;
  }
};

template <typename T>
class Stack
{
private:
  std::shared_ptr<StackNode<T>> top;
  
public:
  void push(T item){
    std::shared_ptr<StackNode<T>> new_top = std::make_shared<StackNode<T>>(item,top);
    top = new_top;
  };
  T pop(){
    if (top == nullptr){
      std::cout << "stack is empty" << std::endl;
      exit(1);
    }
    T item = top.get()->GetItem();
    top = top.get()->GetNext();
    return item;
  };
  T peek(){
    if (top == nullptr){
      std::cout << "stack is empty" << std::endl;
      exit(1);
    }
    return top.item_;
  };
  bool isEmpty(){
    if (top == nullptr){
      return true;
    }
    return false;
  };
};

int main(int argc, char *argv[])
{
  Stack<int> mystack;
  mystack.push(3);
  mystack.push(5);
  std::cout << mystack.pop() << std::endl;
  std::cout << mystack.pop() << std::endl;
  std::cout << "is empty = " << mystack.isEmpty() << std::endl;
  return 0;
}




