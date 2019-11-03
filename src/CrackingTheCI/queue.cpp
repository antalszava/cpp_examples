#include <iostream>
#include <memory>

template <typename T>
class QueueNode
{
private:
  T item_;
  std::shared_ptr<QueueNode> next_;
public:
  QueueNode(T item, std::shared_ptr<QueueNode> next)
      : item_(item), next_(next){};
  T GetItem(){
    return item_;
  }
  std::shared_ptr<QueueNode>GetNext() {
    return next_;
  }
  void SetNext( std::shared_ptr<QueueNode>  next){
    next_ = next;
  }
};

template <typename T>
class Queue
{
private:
  std::shared_ptr<QueueNode<T>> first;
  std::shared_ptr<QueueNode<T>> last;
public:

  void add(T item){
    std::shared_ptr<QueueNode<T>> new_node = std::make_shared<QueueNode<T>>(item, nullptr);
    if (last != nullptr)
      last.get()->SetNext(new_node);
    last = new_node;
    if (first == nullptr){
      first = last;
    }
  }

  T peek(){
    return first.get()->GetItem();
  }

  T remove(){
    if (first == nullptr){
      std::cout << "Queue is empty()" << std::endl;
      exit(1);
    }
    T item = first.get()->GetItem();
    first = first.get()->GetNext();
    if (first == nullptr) {
      last= nullptr;
    }
    return item;    
  }
    
  bool isEmpty(){
    return first == nullptr;
  }
  
};


int main(int argc, char *argv[])
{
  Queue<int> myqueue;
  myqueue.add(3);
  myqueue.add(5);
  std::cout << myqueue.remove() << std::endl;
  std::cout << myqueue.remove() << std::endl;
  std::cout << "is empty = " << myqueue.isEmpty() << std::endl;
  return 0;
}
