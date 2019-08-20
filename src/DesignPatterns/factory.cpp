#include <map>
#include <iostream>

class Shape
{
public:
  virtual void shape_print(){std::cout << " I am Shape Base clas " << std::endl;};
};

class Line : public Shape
{
public:
  void shape_print(){std::cout << " I am Line Derived class " << std::endl;};
};

  
class ShapeFactory
{
public:
  typedef Shape* (*CreateShapeCallback)();
private:
  typedef std::map<int, CreateShapeCallback> CallbackMap;
public:
  static bool RegisterShape(int ShapeId, CreateShapeCallback CreateFn);
  static bool UnRegisterShape(int ShapeId);
  static Shape* CreateShape(int ShapeId);
private:
  CallbackMap callbacks_;
};


namespace {
  // #include <iostream>
  Shape* CreateLine(){
    return new Line;
  }
  const int LINE = 1;
  const bool registered = ShapeFactory().RegisterShape(LINE, CreateLine);
// std::cout << "registered line" << std::endl;
}

bool ShapeFactory::RegisterShape(int shapeId, CreateShapeCallback createFn){
  return callbacks_.insert(CallbackMap::value_type(shapeId,createFn)).second;
}

bool ShapeFactory::UnRegisterShape(int shapeId){
  return callbacks_.erase(shapeId) == 1;
}

Shape* ShapeFactory::CreateShape(int shapeId)
{
  CallbackMap::const_iterator i = callbacks_.find(shapeId);
  if (i == callbacks_.end())
    {
      throw std::runtime_error("Unknown Shape ID");
    }
  return (i->second)();
}

int main(int argc, char *argv[])
{
  Shape* line = ShapeFactory().CreateShape(1);
  line->shape_print();
  delete line;
  return 0;
}
